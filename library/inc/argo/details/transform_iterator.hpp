#ifndef HEADER_argo_transform_iterator_hpp_INCLUDE_GUARD
#define HEADER_argo_transform_iterator_hpp_INCLUDE_GUARD

#include <cassert>
#include <functional>
#include <iterator>
#include <type_traits>

namespace argo { namespace details {

    namespace transformation {
    
        template<typename ReturnType>
        struct dereference
        {
            template<typename It>
            ReturnType operator()(It it) const
            {
                const auto &ptr = *it;
                assert(!!ptr);
                return *ptr;
            }
        };

        template<typename ReturnType>
        struct mapped_type
        {
            template<typename It>
            ReturnType operator()(It it) const { return it->second; }
        };

        template<typename ReturnType>
        struct dereference_mapped_type
        {
            template<typename It>
            ReturnType operator()(It it) const { return *it->second; }
        };

    }
    
    //Transforms the underlying iterator upon dereferencing
    template<typename ResultType, typename It>
    class transform_iterator
    {
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = ResultType;
        using pointer = value_type;
        using reference = value_type;
        using iterator_category = typename std::iterator_traits<It>::iterator_category;

        using transformation_type = std::function<ResultType(It)>;
        
        explicit transform_iterator(const transformation_type &f, It iterator):
            f_(f),
            iterator_(iterator)
        {}
        explicit transform_iterator(It iterator):
            f_(transformation_type{}),
            iterator_(iterator)
        {}
        
        value_type operator*() const { return f_(iterator_); }
        
        pointer operator->() const { return &f_(iterator_); }
        
        transform_iterator &operator++()
        {
            ++iterator_;
            return *this;
        }
        
        transform_iterator operator++(int)
        {
            transform_iterator tmp{*this};
            this->operator++();
            return tmp;
        }
        
        transform_iterator &operator--()
        {
            --iterator_;
            return *this;
        }
        
        transform_iterator operator--(int)
        {
            transform_iterator tmp{*this};
            this->operator--();
            return tmp;
        }
        
        transform_iterator &operator+=(const unsigned int n)
        {
            iterator_ += n;
            return *this;
        }
        
        transform_iterator &operator-=(const unsigned int n)
        {
            iterator_ -= n;
            return *this;
        }
        
        transform_iterator operator+(const unsigned int n) const
        {
            transform_iterator tmp{*this};
            tmp += n;
            return tmp;
        }
        
        transform_iterator operator-(const unsigned int n) const
        {
            transform_iterator tmp{*this};
            tmp -= n;
            return tmp;
        }
        
        difference_type operator-(const transform_iterator &other) const { return iterator_ - other.iterator_; }
        
        bool operator==(const transform_iterator &other) const { return iterator_ == other.iterator_; }
        
        bool operator!=(const transform_iterator &other) const { return !this->operator==(other); }

        bool operator<(const transform_iterator &other) const { return iterator_ < other.iterator_; }

        It iterator() const { return iterator_; }
        
    private:
        transformation_type f_;
        It iterator_;
    };
    
    template<typename ResultType, typename It>
    transform_iterator<ResultType, It> make_transform_iterator(typename transform_iterator<ResultType, It>::transformation_type f, It iterator) { return transform_iterator<ResultType, It>{f, iterator}; }
    
} }

#endif
