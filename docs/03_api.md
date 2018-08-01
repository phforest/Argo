# namespace `argo` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::ostream & `[`operator<<`](#_argo_8hpp_1a1c2b3b20b4e380858e3d64bacc56bb30)`(std::ostream & os,const `[`Result`](#structargo_1_1_result)` & result)`            | 
`public inline std::ostream & `[`operator<<`](#_argo_8hpp_1adb97e90b14e148cc7eb357b6c8d71827)`(std::ostream & os,const `[`Name`](#structargo_1_1_name)` & name)`            | 
`public template<>`  <br/>[`details::optional`](#classargo_1_1details_1_1optional)`< Type > `[`convert`](#_argo_8hpp_1a027fafbd44c0a3f1628ab38ba64d479c)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)`            | 
`public inline bool `[`has_version`](#_argo_8hpp_1a5092eaa54fc00dcec00fdbc39bef8baf)`(const `[`program::Info`](#structargo_1_1program_1_1_info)` & program)`            | 
`public inline unsigned int `[`max_option_length`](#_argo_8hpp_1a038cd3319719695fdbff4ab3097b38a3)`(const std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > & options)`            | 
`public template<>`  <br/>`bool `[`is_type`](#_argo_8hpp_1ab47478489dc7ef655445b81dd625817c)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)`            | 
`public inline std::string `[`basename_of`](#_argo_8hpp_1abf551aee6a02e9e949ea4713f00ee7b7)`(const std::string & path)`            | 
`public template<>`  <br/>[`details::raii`](#classargo_1_1details_1_1raii)`< ConstructionCB, DestructionCB > `[`make_raii`](#_argo_8hpp_1ab5506c3baa1f640896c7eedcd9f80efa)`(const ConstructionCB & on_construction,const DestructionCB & on_destruction)`            | 
`public template<>`  <br/>[`details::raii`](#classargo_1_1details_1_1raii)< std::function< void()`>, DestructionCB > `[`make_raii`](#_argo_8hpp_1a0e51f3197bc989bd9e7943a852f96765)`(const DestructionCB & on_destruction)`            | 
`class `[`argo::Arguments`](#classargo_1_1_arguments) | 
`class `[`argo::Context`](#classargo_1_1_context) | 
`class `[`argo::Handlers`](#classargo_1_1_handlers) | 
`class `[`argo::ResponseFile`](#classargo_1_1_response_file) | 
`struct `[`argo::Configuration`](#structargo_1_1_configuration) | 
`struct `[`argo::Name`](#structargo_1_1_name) | 
`struct `[`argo::Result`](#structargo_1_1_result) | 

## Members

#### `public inline std::ostream & `[`operator<<`](#_argo_8hpp_1a1c2b3b20b4e380858e3d64bacc56bb30)`(std::ostream & os,const `[`Result`](#structargo_1_1_result)` & result)` 

#### `public inline std::ostream & `[`operator<<`](#_argo_8hpp_1adb97e90b14e148cc7eb357b6c8d71827)`(std::ostream & os,const `[`Name`](#structargo_1_1_name)` & name)` 

#### `public template<>`  <br/>[`details::optional`](#classargo_1_1details_1_1optional)`< Type > `[`convert`](#_argo_8hpp_1a027fafbd44c0a3f1628ab38ba64d479c)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)` 

#### `public inline bool `[`has_version`](#_argo_8hpp_1a5092eaa54fc00dcec00fdbc39bef8baf)`(const `[`program::Info`](#structargo_1_1program_1_1_info)` & program)` 

#### `public inline unsigned int `[`max_option_length`](#_argo_8hpp_1a038cd3319719695fdbff4ab3097b38a3)`(const std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > & options)` 

#### `public template<>`  <br/>`bool `[`is_type`](#_argo_8hpp_1ab47478489dc7ef655445b81dd625817c)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` 

#### `public inline std::string `[`basename_of`](#_argo_8hpp_1abf551aee6a02e9e949ea4713f00ee7b7)`(const std::string & path)` 

#### `public template<>`  <br/>[`details::raii`](#classargo_1_1details_1_1raii)`< ConstructionCB, DestructionCB > `[`make_raii`](#_argo_8hpp_1ab5506c3baa1f640896c7eedcd9f80efa)`(const ConstructionCB & on_construction,const DestructionCB & on_destruction)` 

#### `public template<>`  <br/>[`details::raii`](#classargo_1_1details_1_1raii)< std::function< void()`>, DestructionCB > `[`make_raii`](#_argo_8hpp_1a0e51f3197bc989bd9e7943a852f96765)`(const DestructionCB & on_destruction)` 

# class `argo::Arguments` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Arguments`](#classargo_1_1_arguments_1abb3e8062a8a31ba7c3ed1b5b4514bcce)`(const `[`Configuration`](#structargo_1_1_configuration)` & config)` | 
`public inline bool `[`add`](#classargo_1_1_arguments_1a20be2f38761485cc86dff6f7617c947d)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` | 
`public inline bool `[`add`](#classargo_1_1_arguments_1a932029d4536cbbf1b681633b7ebdffe9)`(const `[`Arguments`](#classargo_1_1_arguments)` & arguments,const bool replace)` | 
`public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1_arguments_1af4de2eee97984a6c2e4633d68e23469a)`(Args &&... args)` | 
`public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1_arguments_1a08c84c89016f31412a2466468444efb6)`(Args &&... args)` | 
`public inline void `[`set_formatter`](#classargo_1_1_arguments_1a053e23a23b6fed16f0bae6bc1d388c55)`(formatter::Ptr && formatter)` | 
`public inline bool `[`is_valid`](#classargo_1_1_arguments_1a6dd58b15d3c1ea0101a449ae3b118f0a)`() const` | 
`public inline `[`Result`](#structargo_1_1_result)` `[`parse`](#classargo_1_1_arguments_1ae28e7726de829c5aad2255efc1d5ba26)`(RawList raw_arguments,const bool skip_first_argument)` | 
`public template<>`  <br/>`inline `[`Result`](#structargo_1_1_result)` `[`parse`](#classargo_1_1_arguments_1a0ca0309ccbdb03cb245b78c9bde95e5c)`(unsigned int argc,CharArrayType argv,const bool skip_first_argument)` | 
`public inline bool `[`print_help`](#classargo_1_1_arguments_1a1a52921cae7206536815357c59e41573)`(std::ostream & os)` | 
`public inline bool `[`print_version`](#classargo_1_1_arguments_1a2c48faf6ad222b66fa08235cec95062f)`(std::ostream & os)` | 

## Members

#### `public inline  explicit `[`Arguments`](#classargo_1_1_arguments_1abb3e8062a8a31ba7c3ed1b5b4514bcce)`(const `[`Configuration`](#structargo_1_1_configuration)` & config)` 

#### `public inline bool `[`add`](#classargo_1_1_arguments_1a20be2f38761485cc86dff6f7617c947d)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` 

#### `public inline bool `[`add`](#classargo_1_1_arguments_1a932029d4536cbbf1b681633b7ebdffe9)`(const `[`Arguments`](#classargo_1_1_arguments)` & arguments,const bool replace)` 

#### `public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1_arguments_1af4de2eee97984a6c2e4633d68e23469a)`(Args &&... args)` 

#### `public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1_arguments_1a08c84c89016f31412a2466468444efb6)`(Args &&... args)` 

#### `public inline void `[`set_formatter`](#classargo_1_1_arguments_1a053e23a23b6fed16f0bae6bc1d388c55)`(formatter::Ptr && formatter)` 

#### `public inline bool `[`is_valid`](#classargo_1_1_arguments_1a6dd58b15d3c1ea0101a449ae3b118f0a)`() const` 

#### `public inline `[`Result`](#structargo_1_1_result)` `[`parse`](#classargo_1_1_arguments_1ae28e7726de829c5aad2255efc1d5ba26)`(RawList raw_arguments,const bool skip_first_argument)` 

#### `public template<>`  <br/>`inline `[`Result`](#structargo_1_1_result)` `[`parse`](#classargo_1_1_arguments_1a0ca0309ccbdb03cb245b78c9bde95e5c)`(unsigned int argc,CharArrayType argv,const bool skip_first_argument)` 

#### `public inline bool `[`print_help`](#classargo_1_1_arguments_1a1a52921cae7206536815357c59e41573)`(std::ostream & os)` 

#### `public inline bool `[`print_version`](#classargo_1_1_arguments_1a2c48faf6ad222b66fa08235cec95062f)`(std::ostream & os)` 

# class `argo::Context` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Context`](#classargo_1_1_context_1ad9d928539bf1d3a5fc5d439a578ab081)`(const `[`Configuration`](#structargo_1_1_configuration)` & config)` | 
`public inline const `[`program::Info`](#structargo_1_1program_1_1_info)` & `[`program`](#classargo_1_1_context_1afa32ce783c899c2ca976194acacabdec)`() const` | 
`public inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1_context_1a35e053920b57b28fea7390e81645e94d)`()` | 
`public inline void `[`set_option`](#classargo_1_1_context_1a509a0ebe9be7c23196d2c876de32c9a2)`(`[`handler::Option`](#classargo_1_1handler_1_1_option)` & option)` | 
`public inline `[`Result`](#structargo_1_1_result)` & `[`result`](#classargo_1_1_context_1a4f452397d450f509929bffb8cf4b68c6)`()` | 
`public inline `[`formatter::IFormatter`](#classargo_1_1formatter_1_1_i_formatter)` & `[`formatter`](#classargo_1_1_context_1a979dfb7c35a07403bfa60c4cbc16d3a6)`()` | 
`public inline void `[`set_formatter`](#classargo_1_1_context_1aea0e62a0858aed9feac08bd8ce631c0f)`(`[`formatter::IFormatter`](#classargo_1_1formatter_1_1_i_formatter)` & formatter)` | 
`public inline const `[`Handlers`](#classargo_1_1_handlers)` & `[`handlers`](#classargo_1_1_context_1afd2814676194b920a322f32c2ac1438c)`() const` | 
`public inline void `[`set_handlers`](#classargo_1_1_context_1a153c1d3360f353b70cf4050617de1db9)`(`[`Handlers`](#classargo_1_1_handlers)` & handlers)` | 
`public std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > `[`options_all`](#classargo_1_1_context_1a783a2464d9b9f5426e4dbd2a7088cffd)`(const OptionFilter & filter) const` | 
`public std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > `[`options_standalone`](#classargo_1_1_context_1ae34b3c524f0e7cb246b07a68a100a825)`(const OptionFilter & filter) const` | 
`public std::vector< `[`handler::group::IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` * > `[`groups_all`](#classargo_1_1_context_1affd148e68d75afee6df57043db0c30fd)`(const GroupFilter & filter) const` | 
`public std::vector< `[`handler::group::IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` * > `[`groups_standalone`](#classargo_1_1_context_1a78533a8b595320e640eebd7bd76f2585)`(const GroupFilter & filter) const` | 
`public inline void `[`error`](#classargo_1_1_context_1a2d6f8e45129a228e447495a8b3113bb7)`()` | 
`public void `[`error`](#classargo_1_1_context_1afef98c75d74243bc34286a7dd04a7a57)`(const std::string & message)` | 
`public inline void `[`abort`](#classargo_1_1_context_1a39ba149916499de5abcfcfe07b550334)`()` | 
`public inline bool `[`is_aborted`](#classargo_1_1_context_1a5a312d88610810cfd5a909fd9d19f3a7)`() const` | 
`public inline void `[`set_guessing_allowed`](#classargo_1_1_context_1a51b5169db5ea021a373fd960f7122bc7)`(const bool state)` | 
`public inline bool `[`is_guessing_allowed`](#classargo_1_1_context_1a6625aaa1a32046725c39f59c99877fac)`() const` | 
`typedef `[`OptionFilter`](#classargo_1_1_context_1a8426b38fd8ac9f52acef00891286a977) | 
`typedef `[`GroupFilter`](#classargo_1_1_context_1a44012f5b6cc4559e85bdc5dde53908ef) | 

## Members

#### `public inline  explicit `[`Context`](#classargo_1_1_context_1ad9d928539bf1d3a5fc5d439a578ab081)`(const `[`Configuration`](#structargo_1_1_configuration)` & config)` 

#### `public inline const `[`program::Info`](#structargo_1_1program_1_1_info)` & `[`program`](#classargo_1_1_context_1afa32ce783c899c2ca976194acacabdec)`() const` 

#### `public inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1_context_1a35e053920b57b28fea7390e81645e94d)`()` 

#### `public inline void `[`set_option`](#classargo_1_1_context_1a509a0ebe9be7c23196d2c876de32c9a2)`(`[`handler::Option`](#classargo_1_1handler_1_1_option)` & option)` 

#### `public inline `[`Result`](#structargo_1_1_result)` & `[`result`](#classargo_1_1_context_1a4f452397d450f509929bffb8cf4b68c6)`()` 

#### `public inline `[`formatter::IFormatter`](#classargo_1_1formatter_1_1_i_formatter)` & `[`formatter`](#classargo_1_1_context_1a979dfb7c35a07403bfa60c4cbc16d3a6)`()` 

#### `public inline void `[`set_formatter`](#classargo_1_1_context_1aea0e62a0858aed9feac08bd8ce631c0f)`(`[`formatter::IFormatter`](#classargo_1_1formatter_1_1_i_formatter)` & formatter)` 

#### `public inline const `[`Handlers`](#classargo_1_1_handlers)` & `[`handlers`](#classargo_1_1_context_1afd2814676194b920a322f32c2ac1438c)`() const` 

#### `public inline void `[`set_handlers`](#classargo_1_1_context_1a153c1d3360f353b70cf4050617de1db9)`(`[`Handlers`](#classargo_1_1_handlers)` & handlers)` 

#### `public std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > `[`options_all`](#classargo_1_1_context_1a783a2464d9b9f5426e4dbd2a7088cffd)`(const OptionFilter & filter) const` 

#### `public std::vector< `[`handler::Option`](#classargo_1_1handler_1_1_option)` * > `[`options_standalone`](#classargo_1_1_context_1ae34b3c524f0e7cb246b07a68a100a825)`(const OptionFilter & filter) const` 

#### `public std::vector< `[`handler::group::IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` * > `[`groups_all`](#classargo_1_1_context_1affd148e68d75afee6df57043db0c30fd)`(const GroupFilter & filter) const` 

#### `public std::vector< `[`handler::group::IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` * > `[`groups_standalone`](#classargo_1_1_context_1a78533a8b595320e640eebd7bd76f2585)`(const GroupFilter & filter) const` 

#### `public inline void `[`error`](#classargo_1_1_context_1a2d6f8e45129a228e447495a8b3113bb7)`()` 

#### `public void `[`error`](#classargo_1_1_context_1afef98c75d74243bc34286a7dd04a7a57)`(const std::string & message)` 

#### `public inline void `[`abort`](#classargo_1_1_context_1a39ba149916499de5abcfcfe07b550334)`()` 

#### `public inline bool `[`is_aborted`](#classargo_1_1_context_1a5a312d88610810cfd5a909fd9d19f3a7)`() const` 

#### `public inline void `[`set_guessing_allowed`](#classargo_1_1_context_1a51b5169db5ea021a373fd960f7122bc7)`(const bool state)` 

#### `public inline bool `[`is_guessing_allowed`](#classargo_1_1_context_1a6625aaa1a32046725c39f59c99877fac)`() const` 

#### `typedef `[`OptionFilter`](#classargo_1_1_context_1a8426b38fd8ac9f52acef00891286a977) 

#### `typedef `[`GroupFilter`](#classargo_1_1_context_1a44012f5b6cc4559e85bdc5dde53908ef) 

# class `argo::Handlers` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Handlers`](#classargo_1_1_handlers_1aac0c7eac57014e18db84ee9b29eb8862)`() = default` | 
`public inline  `[`Handlers`](#classargo_1_1_handlers_1af3ce6b2829589e651d854596d943279c)`(const `[`Handlers`](#classargo_1_1_handlers)` & handlers)` | 
`public inline  `[`Handlers`](#classargo_1_1_handlers_1a04f4e6dfaca308352e6758e3d3664a0f)`(`[`Handlers`](#classargo_1_1_handlers)` && handlers)` | 
`public inline `[`Handlers`](#classargo_1_1_handlers)` & `[`operator=`](#classargo_1_1_handlers_1a6dd97753cb8012a6808e9ff7f030a511)`(`[`Handlers`](#classargo_1_1_handlers)` handlers)` | 
`public inline `[`Handlers`](#classargo_1_1_handlers)` & `[`operator=`](#classargo_1_1_handlers_1a32b0a99c021deae21909cf7e0377e626)`(`[`Handlers`](#classargo_1_1_handlers)` && handlers)` | 
`public inline `[`const_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`begin`](#classargo_1_1_handlers_1a3fe3c1a9127ae896da0ff6394bd6a798)`() const` | 
`public inline `[`iterator`](#classargo_1_1details_1_1transform__iterator)` `[`begin`](#classargo_1_1_handlers_1abdd8e1cfd0d46dabef1b6be1b46d29f9)`()` | 
`public inline `[`const_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`end`](#classargo_1_1_handlers_1aa5ced2dc07eff2dd8d80ff6266f55349)`() const` | 
`public inline `[`iterator`](#classargo_1_1details_1_1transform__iterator)` `[`end`](#classargo_1_1_handlers_1a44ab4af0c44de9225aa4c011b785edb6)`()` | 
`public inline bool `[`empty`](#classargo_1_1_handlers_1adf50d8b098d4664e50323a0059ef38fd)`() const` | 
`public inline std::size_t `[`size`](#classargo_1_1_handlers_1a8642bb9197f617c093ea501accca2573)`() const` | 
`public inline bool `[`has`](#classargo_1_1_handlers_1ac9afe97a9f126fab8e08f89b0896c828)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler) const` | 
`public inline bool `[`add`](#classargo_1_1_handlers_1ac39089d17084b68d8e2b3b122acb60c0)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` | 
`public inline `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & `[`put`](#classargo_1_1_handlers_1aaf2cdd637c665d243bc5d800d1be1fb9)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` | 
`public template<>`  <br/>`inline std::vector< T * > `[`filter`](#classargo_1_1_handlers_1a7e21e711eb363ec72e5de69d54edd947)`() const` | 
`typedef `[`value_type`](#classargo_1_1_handlers_1a105dfd89566d09b1c9e8d8ec0afd798c) | 
`typedef `[`reference`](#classargo_1_1_handlers_1a84936ecaf318b0351f166df631174623) | 
`typedef `[`const_iterator`](#classargo_1_1_handlers_1aaa24ba7b3bb2676af025335cc43ec348) | 
`typedef `[`iterator`](#classargo_1_1_handlers_1ab1b36b4a2c051fb66b69e0a8894335bd) | 

## Members

#### `public  `[`Handlers`](#classargo_1_1_handlers_1aac0c7eac57014e18db84ee9b29eb8862)`() = default` 

#### `public inline  `[`Handlers`](#classargo_1_1_handlers_1af3ce6b2829589e651d854596d943279c)`(const `[`Handlers`](#classargo_1_1_handlers)` & handlers)` 

#### `public inline  `[`Handlers`](#classargo_1_1_handlers_1a04f4e6dfaca308352e6758e3d3664a0f)`(`[`Handlers`](#classargo_1_1_handlers)` && handlers)` 

#### `public inline `[`Handlers`](#classargo_1_1_handlers)` & `[`operator=`](#classargo_1_1_handlers_1a6dd97753cb8012a6808e9ff7f030a511)`(`[`Handlers`](#classargo_1_1_handlers)` handlers)` 

#### `public inline `[`Handlers`](#classargo_1_1_handlers)` & `[`operator=`](#classargo_1_1_handlers_1a32b0a99c021deae21909cf7e0377e626)`(`[`Handlers`](#classargo_1_1_handlers)` && handlers)` 

#### `public inline `[`const_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`begin`](#classargo_1_1_handlers_1a3fe3c1a9127ae896da0ff6394bd6a798)`() const` 

#### `public inline `[`iterator`](#classargo_1_1details_1_1transform__iterator)` `[`begin`](#classargo_1_1_handlers_1abdd8e1cfd0d46dabef1b6be1b46d29f9)`()` 

#### `public inline `[`const_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`end`](#classargo_1_1_handlers_1aa5ced2dc07eff2dd8d80ff6266f55349)`() const` 

#### `public inline `[`iterator`](#classargo_1_1details_1_1transform__iterator)` `[`end`](#classargo_1_1_handlers_1a44ab4af0c44de9225aa4c011b785edb6)`()` 

#### `public inline bool `[`empty`](#classargo_1_1_handlers_1adf50d8b098d4664e50323a0059ef38fd)`() const` 

#### `public inline std::size_t `[`size`](#classargo_1_1_handlers_1a8642bb9197f617c093ea501accca2573)`() const` 

#### `public inline bool `[`has`](#classargo_1_1_handlers_1ac9afe97a9f126fab8e08f89b0896c828)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler) const` 

#### `public inline bool `[`add`](#classargo_1_1_handlers_1ac39089d17084b68d8e2b3b122acb60c0)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` 

#### `public inline `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & `[`put`](#classargo_1_1_handlers_1aaf2cdd637c665d243bc5d800d1be1fb9)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` 

#### `public template<>`  <br/>`inline std::vector< T * > `[`filter`](#classargo_1_1_handlers_1a7e21e711eb363ec72e5de69d54edd947)`() const` 

#### `typedef `[`value_type`](#classargo_1_1_handlers_1a105dfd89566d09b1c9e8d8ec0afd798c) 

#### `typedef `[`reference`](#classargo_1_1_handlers_1a84936ecaf318b0351f166df631174623) 

#### `typedef `[`const_iterator`](#classargo_1_1_handlers_1aaa24ba7b3bb2676af025335cc43ec348) 

#### `typedef `[`iterator`](#classargo_1_1_handlers_1ab1b36b4a2c051fb66b69e0a8894335bd) 

# class `argo::ResponseFile` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline bool `[`parse`](#classargo_1_1_response_file_1aa11760577496182d7a131afb33379eb3)`(const std::string & filename)` | 
`public inline std::string `[`filename`](#classargo_1_1_response_file_1a6fe21c7bd1aedca42eb7cfbb6e9425ac)`() const` | 
`public inline int `[`argc`](#classargo_1_1_response_file_1a390a09c7fdb1638ae7f5744fc3c31efc)`() const` | 
`public inline std::vector< std::string > `[`argv`](#classargo_1_1_response_file_1a33e0dad2efb3c22c3e5a771070f1c5ec)`() const` | 

## Members

#### `public inline bool `[`parse`](#classargo_1_1_response_file_1aa11760577496182d7a131afb33379eb3)`(const std::string & filename)` 

#### `public inline std::string `[`filename`](#classargo_1_1_response_file_1a6fe21c7bd1aedca42eb7cfbb6e9425ac)`() const` 

#### `public inline int `[`argc`](#classargo_1_1_response_file_1a390a09c7fdb1638ae7f5744fc3c31efc)`() const` 

#### `public inline std::vector< std::string > `[`argv`](#classargo_1_1_response_file_1a33e0dad2efb3c22c3e5a771070f1c5ec)`() const` 

# struct `argo::Configuration` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`program::Info`](#structargo_1_1program_1_1_info)` `[`program`](#structargo_1_1_configuration_1ad1bf7cb1b1a94a4fdc20473372ffa5a1) | 
`public bool `[`add_help`](#structargo_1_1_configuration_1a7ce4ab870ca65f901e2a1a9f13179947) | 
`public bool `[`add_version`](#structargo_1_1_configuration_1aa389cceca55ec2bb197918de7d3293b1) | 

## Members

#### `public `[`program::Info`](#structargo_1_1program_1_1_info)` `[`program`](#structargo_1_1_configuration_1ad1bf7cb1b1a94a4fdc20473372ffa5a1) 

#### `public bool `[`add_help`](#structargo_1_1_configuration_1a7ce4ab870ca65f901e2a1a9f13179947) 

#### `public bool `[`add_version`](#structargo_1_1_configuration_1aa389cceca55ec2bb197918de7d3293b1) 

# struct `argo::Name` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::string `[`hash`](#structargo_1_1_name_1a5d782e2c9a00dc838fd4d4a3a12a4192)`() const` | 
`public inline `[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > `[`shorthand`](#structargo_1_1_name_1a5030cf3aa933c5f1b279aa6e4e50633e)`() const` | 
`public inline bool `[`shorthand`](#structargo_1_1_name_1a22d3e789c8ce7b4f26b729930b693e3b)`(const std::string & name)` | 
`public inline `[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > `[`longhand`](#structargo_1_1_name_1a1324669e4f1f3020f77f4c4a8519b775)`() const` | 
`public inline bool `[`longhand`](#structargo_1_1_name_1a7f492ae56fb2903254610e28c6fae23d)`(const std::string & name)` | 
`public inline std::string `[`str`](#structargo_1_1_name_1a877bce463cc7dfc2d660625d86f88cc5)`() const` | 
`public template<>`  <br/>`inline T & `[`print`](#structargo_1_1_name_1a5f98a626e09514e391a099c780e3ee9b)`(T & t) const` | 

## Members

#### `public inline std::string `[`hash`](#structargo_1_1_name_1a5d782e2c9a00dc838fd4d4a3a12a4192)`() const` 

#### `public inline `[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > `[`shorthand`](#structargo_1_1_name_1a5030cf3aa933c5f1b279aa6e4e50633e)`() const` 

#### `public inline bool `[`shorthand`](#structargo_1_1_name_1a22d3e789c8ce7b4f26b729930b693e3b)`(const std::string & name)` 

#### `public inline `[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > `[`longhand`](#structargo_1_1_name_1a1324669e4f1f3020f77f4c4a8519b775)`() const` 

#### `public inline bool `[`longhand`](#structargo_1_1_name_1a7f492ae56fb2903254610e28c6fae23d)`(const std::string & name)` 

#### `public inline std::string `[`str`](#structargo_1_1_name_1a877bce463cc7dfc2d660625d86f88cc5)`() const` 

#### `public template<>`  <br/>`inline T & `[`print`](#structargo_1_1_name_1a5f98a626e09514e391a099c780e3ee9b)`(T & t) const` 

# struct `argo::Result` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`success`](#structargo_1_1_result_1a05d26ce05698751c250bd958cc9911f2) | 
`public bool `[`requested_abort`](#structargo_1_1_result_1a1b252503a9a1f26bafdf6104fc1bc2d4) | 
`public std::string `[`message`](#structargo_1_1_result_1aa53bececeb90b81b17ab92717017071b) | 
`public unsigned int `[`nr_options`](#structargo_1_1_result_1a7ba4c0f2d16c01419091bbf0eb077114) | 
`public unsigned int `[`nr_args`](#structargo_1_1_result_1ac3c8de753ffb8d4a24ee475b976b2ff1) | 

## Members

#### `public bool `[`success`](#structargo_1_1_result_1a05d26ce05698751c250bd958cc9911f2) 

#### `public bool `[`requested_abort`](#structargo_1_1_result_1a1b252503a9a1f26bafdf6104fc1bc2d4) 

#### `public std::string `[`message`](#structargo_1_1_result_1aa53bececeb90b81b17ab92717017071b) 

#### `public unsigned int `[`nr_options`](#structargo_1_1_result_1a7ba4c0f2d16c01419091bbf0eb077114) 

#### `public unsigned int `[`nr_args`](#structargo_1_1_result_1ac3c8de753ffb8d4a24ee475b976b2ff1) 

# namespace `argo::action` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`callback`](#_argo_8hpp_1aeecef368ef9cf097b9c9114edf2bbea2)`(typename `[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits >::callback_type & cb)`            | 
`public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a03dd631fa9fd52a03ce6efa2adea1201)`(const std::function< bool(const std::string &)> & cb)`            | 
`public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a5614fdf550191a535c7aeb3eac45bb11)`(const std::function< bool()> & cb)`            | 
`public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`callback`](#_argo_8hpp_1a47425a7b1b79f8c5f599a692765cafcd)`(typename `[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits >::callback_type_with_context & cb)`            | 
`public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a78155bca7a68f3ae2f3726a15f8a1fa4)`(const std::function< bool(`[`Context`](#classargo_1_1_context) &, const std::string &)`> & cb)`            | 
`public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a411188e0fc09823ad40ae384c1e65d59)`(const std::function< bool(`[`Context`](#classargo_1_1_context) &)`> & cb)`            | 
`public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`store`](#_argo_8hpp_1aea1781f4703ad25024eebc691c33344e)`(Type & destination)`            | 
`public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`store`](#_argo_8hpp_1a3472ec963144fd7855b781c02b7f169f)`(std::vector< Type > & destination)`            | 
`public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< std::string, ConversionTraits > `[`store_const`](#_argo_8hpp_1a55c1db1edccb255d2fa2d3e6e3a56914)`(Type & destination,ConstType value)`            | 
`public template<>`  <br/>[`Print`](#classargo_1_1action_1_1_print)` `[`print`](#_argo_8hpp_1a1e23059f9621a3828554d55db69d2b9e)`(Args &&... args)`            | 
`class `[`argo::action::Callback`](#classargo_1_1action_1_1_callback) | 
`class `[`argo::action::IAction`](#classargo_1_1action_1_1_i_action) | 
`class `[`argo::action::Print`](#classargo_1_1action_1_1_print) | 

## Members

#### `public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`callback`](#_argo_8hpp_1aeecef368ef9cf097b9c9114edf2bbea2)`(typename `[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits >::callback_type & cb)` 

#### `public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a03dd631fa9fd52a03ce6efa2adea1201)`(const std::function< bool(const std::string &)> & cb)` 

#### `public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a5614fdf550191a535c7aeb3eac45bb11)`(const std::function< bool()> & cb)` 

#### `public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`callback`](#_argo_8hpp_1a47425a7b1b79f8c5f599a692765cafcd)`(typename `[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits >::callback_type_with_context & cb)` 

#### `public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a78155bca7a68f3ae2f3726a15f8a1fa4)`(const std::function< bool(`[`Context`](#classargo_1_1_context) &, const std::string &)`> & cb)` 

#### `public inline `[`Callback`](#classargo_1_1action_1_1_callback)`< std::string > `[`callback`](#_argo_8hpp_1a411188e0fc09823ad40ae384c1e65d59)`(const std::function< bool(`[`Context`](#classargo_1_1_context) &)`> & cb)` 

#### `public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`store`](#_argo_8hpp_1aea1781f4703ad25024eebc691c33344e)`(Type & destination)` 

#### `public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< Type, ConversionTraits > `[`store`](#_argo_8hpp_1a3472ec963144fd7855b781c02b7f169f)`(std::vector< Type > & destination)` 

#### `public template<>`  <br/>[`Callback`](#classargo_1_1action_1_1_callback)`< std::string, ConversionTraits > `[`store_const`](#_argo_8hpp_1a55c1db1edccb255d2fa2d3e6e3a56914)`(Type & destination,ConstType value)` 

#### `public template<>`  <br/>[`Print`](#classargo_1_1action_1_1_print)` `[`print`](#_argo_8hpp_1a1e23059f9621a3828554d55db69d2b9e)`(Args &&... args)` 

# class `argo::action::Callback` 

```
class argo::action::Callback
  : public argo::action::IAction
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Callback`](#classargo_1_1action_1_1_callback_1a82986427204b5b7e5a1ec5358a48c562)`(const callback_type & callback)` | 
`public inline  explicit `[`Callback`](#classargo_1_1action_1_1_callback_1a376928f20c366c04f7458104c23e449c)`(const callback_with_context_type & callback)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1action_1_1_callback_1a76e14a1db52a73e0254b5e00815ddb5e)`() const` | 
`public inline virtual bool `[`apply`](#classargo_1_1action_1_1_callback_1a3fa2117067d9917035a6dde7f9136307)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)` | 
`typedef `[`callback_type`](#classargo_1_1action_1_1_callback_1a702b7e93ee004166665f6bb42eccbd1d) | 
`typedef `[`callback_with_context_type`](#classargo_1_1action_1_1_callback_1a2a7d6498c9fa86d384b3aa30d9f8bbe0) | 

## Members

#### `public inline  explicit `[`Callback`](#classargo_1_1action_1_1_callback_1a82986427204b5b7e5a1ec5358a48c562)`(const callback_type & callback)` 

#### `public inline  explicit `[`Callback`](#classargo_1_1action_1_1_callback_1a376928f20c366c04f7458104c23e449c)`(const callback_with_context_type & callback)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1action_1_1_callback_1a76e14a1db52a73e0254b5e00815ddb5e)`() const` 

#### `public inline virtual bool `[`apply`](#classargo_1_1action_1_1_callback_1a3fa2117067d9917035a6dde7f9136307)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)` 

#### `typedef `[`callback_type`](#classargo_1_1action_1_1_callback_1a702b7e93ee004166665f6bb42eccbd1d) 

#### `typedef `[`callback_with_context_type`](#classargo_1_1action_1_1_callback_1a2a7d6498c9fa86d384b3aa30d9f8bbe0) 

# class `argo::action::IAction` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~IAction`](#classargo_1_1action_1_1_i_action_1a5ca99096e1e05cb3bee044f50d42cfbe)`() = default` | 
`public Ptr `[`clone`](#classargo_1_1action_1_1_i_action_1a52f7b3425e70f6c8e6da4d912a475eb2)`() const` | 
`public bool `[`apply`](#classargo_1_1action_1_1_i_action_1a9a209f81db544d677ed182fcbc507dbc)`(`[`Context`](#classargo_1_1_context)` &,const std::string &)` | 

## Members

#### `public virtual  `[`~IAction`](#classargo_1_1action_1_1_i_action_1a5ca99096e1e05cb3bee044f50d42cfbe)`() = default` 

#### `public Ptr `[`clone`](#classargo_1_1action_1_1_i_action_1a52f7b3425e70f6c8e6da4d912a475eb2)`() const` 

#### `public bool `[`apply`](#classargo_1_1action_1_1_i_action_1a9a209f81db544d677ed182fcbc507dbc)`(`[`Context`](#classargo_1_1_context)` &,const std::string &)` 

# class `argo::action::Print` 

```
class argo::action::Print
  : public argo::action::IAction
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Print`](#classargo_1_1action_1_1_print_1aba77074e8a92da9e29d53c3de6cf2bff)`(std::ostream & os)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1action_1_1_print_1a150b6c6f531ddf5fe4e51fe4dc1e8c46)`() const` | 
`public inline virtual bool `[`apply`](#classargo_1_1action_1_1_print_1a0e9ed86cc0522560604070aef1edcd66)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)` | 

## Members

#### `public inline  explicit `[`Print`](#classargo_1_1action_1_1_print_1aba77074e8a92da9e29d53c3de6cf2bff)`(std::ostream & os)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1action_1_1_print_1a150b6c6f531ddf5fe4e51fe4dc1e8c46)`() const` 

#### `public inline virtual bool `[`apply`](#classargo_1_1action_1_1_print_1a0e9ed86cc0522560604070aef1edcd66)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & value)` 

# namespace `argo::details` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`bool `[`pass_through`](#_argo_8hpp_1a6b92168fbe6329b22a81449f7553e4d6)`(const T &)`            | 
`public template<>`  <br/>[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)`< ResultType, It > `[`make_transform_iterator`](#_argo_8hpp_1a33fba00c4c4df156fa95ee233f3a01af)`(typename `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)`< ResultType, It >::transformation_type f,It iterator)`            | 
`public template<>`  <br/>`std::unique_ptr< T > `[`make_unique`](#_argo_8hpp_1a60d4b8e2a123421036c4557e15d02fc7)`(Args &&... args)`            | 
`public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a970ddd520738b359fa7992c26ee30902)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1acb43909497f3b6eb0750d28374ccf834)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1a728fa4408108e8a9d2d3ba7012705afb)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1a51e1fc519703303b2626be4562676950)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1ad99aedec90a617b2c97df0e626b98223)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a5ce3b2bd4d5a41c74bdae3c6c7f41780)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a2f021c5f465cecf89e2b5e581bedfeb9)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a22b073f980f791226043b3f00e4510a1)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1a1db12dab2567fb0f9ab34939c9b46760)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1acd9876981f25c677ae2d3820b25510b9)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aa1e679afa50388295f01f2f799091f97)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > &,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aaf3ba18d8a0f23b3c2f9c8c7f364c7a3)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1ae77ab0d0433862eeb2003f491aae0fbe)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1a7f2db74817e8285fa1ccef58c03b172c)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > &) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1ae3478211e472b074b14d5e4f25189fe1)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1aa1f27e1b66934ebd404927fe89e5ce42)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > &) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1af122e5ab4e9c165c3978177c2748b2e0)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > &,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a6e630212830821eeb2c5ec47b3eb1a1f)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept`            | 
`public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a331c7c6bdc36822b8201e129527374b7)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1ad1f62b6bdd3e1fc36e0cbc8316f7e3cf)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1a3604edd2618ef43cfde0ea07f12a5fad)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1ac914903b34774d43748f30a6c7a5e87c)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1a3b34a1bf587cf05da4cb2720eebed1bf)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aea1b3c697461d2e6e3ccb2697b80dbec)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1a05679e55272536eb1cd88406d7977f33)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1aedfae9a32183697dcc9d023819b17240)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1adc3033235c5194bc817986d4c618c684)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1a05323737be9a86af0545a7456b8d3fe5)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a4e681e4402809dd35a4ea64710242cc3)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)`            | 
`public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1aafc886ddf8a66380586b9c672b8db2bd)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline void `[`swap`](#_argo_8hpp_1a07f0afc5be35638edaec6cd1a353405f)`(`[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)`            | 
`public template<>`  <br/>`inline `[`optional`](#classargo_1_1details_1_1optional)`< typename std::decay< T >::type > `[`make_optional`](#_argo_8hpp_1a4d8dc4eba9eff7cb6d6c8745a599fcea)`(T && value)`            | 
`class `[`argo::details::optional`](#classargo_1_1details_1_1optional) | 
`class `[`argo::details::raii`](#classargo_1_1details_1_1raii) | 
`class `[`argo::details::transform_iterator`](#classargo_1_1details_1_1transform__iterator) | 
`struct `[`argo::details::nullopt_t`](#structargo_1_1details_1_1nullopt__t) | 

## Members

#### `public template<>`  <br/>`bool `[`pass_through`](#_argo_8hpp_1a6b92168fbe6329b22a81449f7553e4d6)`(const T &)` 

#### `public template<>`  <br/>[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)`< ResultType, It > `[`make_transform_iterator`](#_argo_8hpp_1a33fba00c4c4df156fa95ee233f3a01af)`(typename `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)`< ResultType, It >::transformation_type f,It iterator)` 

#### `public template<>`  <br/>`std::unique_ptr< T > `[`make_unique`](#_argo_8hpp_1a60d4b8e2a123421036c4557e15d02fc7)`(Args &&... args)` 

#### `public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a970ddd520738b359fa7992c26ee30902)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1acb43909497f3b6eb0750d28374ccf834)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1a728fa4408108e8a9d2d3ba7012705afb)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1a51e1fc519703303b2626be4562676950)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1ad99aedec90a617b2c97df0e626b98223)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a5ce3b2bd4d5a41c74bdae3c6c7f41780)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a2f021c5f465cecf89e2b5e581bedfeb9)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a22b073f980f791226043b3f00e4510a1)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1a1db12dab2567fb0f9ab34939c9b46760)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1acd9876981f25c677ae2d3820b25510b9)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aa1e679afa50388295f01f2f799091f97)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > &,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aaf3ba18d8a0f23b3c2f9c8c7f364c7a3)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1ae77ab0d0433862eeb2003f491aae0fbe)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1a7f2db74817e8285fa1ccef58c03b172c)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > &) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1ae3478211e472b074b14d5e4f25189fe1)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1aa1f27e1b66934ebd404927fe89e5ce42)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > &) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1af122e5ab4e9c165c3978177c2748b2e0)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > &,`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a6e630212830821eeb2c5ec47b3eb1a1f)`(`[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)`,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs) noexcept` 

#### `public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1a331c7c6bdc36822b8201e129527374b7)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator==`](#_argo_8hpp_1ad1f62b6bdd3e1fc36e0cbc8316f7e3cf)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1a3604edd2618ef43cfde0ea07f12a5fad)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator!=`](#_argo_8hpp_1ac914903b34774d43748f30a6c7a5e87c)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1a3b34a1bf587cf05da4cb2720eebed1bf)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<`](#_argo_8hpp_1aea1b3c697461d2e6e3ccb2697b80dbec)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1a05679e55272536eb1cd88406d7977f33)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator<=`](#_argo_8hpp_1aedfae9a32183697dcc9d023819b17240)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1adc3033235c5194bc817986d4c618c684)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>`](#_argo_8hpp_1a05323737be9a86af0545a7456b8d3fe5)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1a4e681e4402809dd35a4ea64710242cc3)`(const `[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,const T & rhs)` 

#### `public template<>`  <br/>`inline bool `[`operator>=`](#_argo_8hpp_1aafc886ddf8a66380586b9c672b8db2bd)`(const T & lhs,const `[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline void `[`swap`](#_argo_8hpp_1a07f0afc5be35638edaec6cd1a353405f)`(`[`optional`](#classargo_1_1details_1_1optional)`< T > & lhs,`[`optional`](#classargo_1_1details_1_1optional)`< T > & rhs)` 

#### `public template<>`  <br/>`inline `[`optional`](#classargo_1_1details_1_1optional)`< typename std::decay< T >::type > `[`make_optional`](#_argo_8hpp_1a4d8dc4eba9eff7cb6d6c8745a599fcea)`(T && value)` 

# class `argo::details::optional` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`optional`](#classargo_1_1details_1_1optional_1a74ad772add5a244c2b9699283953ffd2)`() = default` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1a31267f99f37a5cbf9c97b3be07b65e77)`(const T & t)` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1a6cc047bcaf12239def0505d2c1e96bc9)`(T && t)` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1a0f195fc45336aab0cb9373cada2709cd)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other)` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1ab0d2ce1a38946c61b34740a09aa31ab7)`(`[`optional`](#classargo_1_1details_1_1optional)` && other)` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1a880af0289bf2e153bbb1ce4e3dc25235)`(const `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)` & null)` | 
`public inline  `[`optional`](#classargo_1_1details_1_1optional_1ae1b2329880ce7b1f3858ea9f905f902c)`(const std::nullptr_t & null)` | 
`public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1ab28a1c19175dd8a85bac2eb0d92a0927)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other)` | 
`public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a8123fb1654da59b2d8a694d344807998)`(const T & other)` | 
`public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1ac8d3357d620331e4d8952b6aebd738a1)`(T && other)` | 
`public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a2b8d42242dc5c0dbcb9d84edf6519816)`(`[`optional`](#classargo_1_1details_1_1optional)` && other)` | 
`public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a0ce090764b4c0d24d505a2a45c72c589)`(const `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)` & null)` | 
`public inline  `[`~optional`](#classargo_1_1details_1_1optional_1a2d16d1541ffd139fb3f4e3b0a2c24d41)`()` | 
`public inline bool `[`equal`](#classargo_1_1details_1_1optional_1a7bc161add3d16c6214b4cc186b9c4021)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other) const` | 
`public inline bool `[`valid`](#classargo_1_1details_1_1optional_1a88124f4f750dabdcd07ad806d4f4e8fb)`() const` | 
`public inline  explicit `[`operator bool`](#classargo_1_1details_1_1optional_1a0ddf7e7d89f0dd97034bd5fa5b282291)`() const` | 
`public inline void `[`reset`](#classargo_1_1details_1_1optional_1a9ca2d24042f36af0d1628d7995f0ceb3)`()` | 
`public inline T & `[`emplace`](#classargo_1_1details_1_1optional_1a69210fdb41c6d7b473082e5bdc476270)`()` | 
`public inline void `[`set`](#classargo_1_1details_1_1optional_1a499581a358332b71af297f0dccd86383)`(const T & v)` | 
`public inline void `[`set`](#classargo_1_1details_1_1optional_1ad155a083e976242ca02570b077f86127)`(T && v)` | 
`public inline void `[`set_if_unset`](#classargo_1_1details_1_1optional_1ac96d88619e873adcd5477d1ee85bbd7d)`(const T & v)` | 
`public inline const T * `[`get`](#classargo_1_1details_1_1optional_1a4cc176d368937d95c64bc86fbf7e831a)`() const` | 
`public inline const T & `[`operator*`](#classargo_1_1details_1_1optional_1af4b77e5b00a74b19e1b22c5a4e042fd9)`() const` | 
`public inline T & `[`operator*`](#classargo_1_1details_1_1optional_1a851cf8ba919ba87d99b3df314e09dcd3)`()` | 
`public inline const T * `[`operator->`](#classargo_1_1details_1_1optional_1a08d8b10164f173b87be90d1996aa3459)`() const` | 
`public inline T * `[`operator->`](#classargo_1_1details_1_1optional_1aa0b1276c1d5583dc73646acd693918f7)`()` | 
`public inline const T & `[`value_or`](#classargo_1_1details_1_1optional_1a662eba2115a9b26930062f34dc88884b)`(const T & v) const` | 
`typedef `[`value_type`](#classargo_1_1details_1_1optional_1a87fcf67ca38ce1f7f78e6747cb05b4c6) | 

## Members

#### `public  `[`optional`](#classargo_1_1details_1_1optional_1a74ad772add5a244c2b9699283953ffd2)`() = default` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1a31267f99f37a5cbf9c97b3be07b65e77)`(const T & t)` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1a6cc047bcaf12239def0505d2c1e96bc9)`(T && t)` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1a0f195fc45336aab0cb9373cada2709cd)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other)` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1ab0d2ce1a38946c61b34740a09aa31ab7)`(`[`optional`](#classargo_1_1details_1_1optional)` && other)` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1a880af0289bf2e153bbb1ce4e3dc25235)`(const `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)` & null)` 

#### `public inline  `[`optional`](#classargo_1_1details_1_1optional_1ae1b2329880ce7b1f3858ea9f905f902c)`(const std::nullptr_t & null)` 

#### `public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1ab28a1c19175dd8a85bac2eb0d92a0927)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other)` 

#### `public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a8123fb1654da59b2d8a694d344807998)`(const T & other)` 

#### `public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1ac8d3357d620331e4d8952b6aebd738a1)`(T && other)` 

#### `public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a2b8d42242dc5c0dbcb9d84edf6519816)`(`[`optional`](#classargo_1_1details_1_1optional)` && other)` 

#### `public inline `[`optional`](#classargo_1_1details_1_1optional)` & `[`operator=`](#classargo_1_1details_1_1optional_1a0ce090764b4c0d24d505a2a45c72c589)`(const `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t)` & null)` 

#### `public inline  `[`~optional`](#classargo_1_1details_1_1optional_1a2d16d1541ffd139fb3f4e3b0a2c24d41)`()` 

#### `public inline bool `[`equal`](#classargo_1_1details_1_1optional_1a7bc161add3d16c6214b4cc186b9c4021)`(const `[`optional`](#classargo_1_1details_1_1optional)` & other) const` 

#### `public inline bool `[`valid`](#classargo_1_1details_1_1optional_1a88124f4f750dabdcd07ad806d4f4e8fb)`() const` 

#### `public inline  explicit `[`operator bool`](#classargo_1_1details_1_1optional_1a0ddf7e7d89f0dd97034bd5fa5b282291)`() const` 

#### `public inline void `[`reset`](#classargo_1_1details_1_1optional_1a9ca2d24042f36af0d1628d7995f0ceb3)`()` 

#### `public inline T & `[`emplace`](#classargo_1_1details_1_1optional_1a69210fdb41c6d7b473082e5bdc476270)`()` 

#### `public inline void `[`set`](#classargo_1_1details_1_1optional_1a499581a358332b71af297f0dccd86383)`(const T & v)` 

#### `public inline void `[`set`](#classargo_1_1details_1_1optional_1ad155a083e976242ca02570b077f86127)`(T && v)` 

#### `public inline void `[`set_if_unset`](#classargo_1_1details_1_1optional_1ac96d88619e873adcd5477d1ee85bbd7d)`(const T & v)` 

#### `public inline const T * `[`get`](#classargo_1_1details_1_1optional_1a4cc176d368937d95c64bc86fbf7e831a)`() const` 

#### `public inline const T & `[`operator*`](#classargo_1_1details_1_1optional_1af4b77e5b00a74b19e1b22c5a4e042fd9)`() const` 

#### `public inline T & `[`operator*`](#classargo_1_1details_1_1optional_1a851cf8ba919ba87d99b3df314e09dcd3)`()` 

#### `public inline const T * `[`operator->`](#classargo_1_1details_1_1optional_1a08d8b10164f173b87be90d1996aa3459)`() const` 

#### `public inline T * `[`operator->`](#classargo_1_1details_1_1optional_1aa0b1276c1d5583dc73646acd693918f7)`()` 

#### `public inline const T & `[`value_or`](#classargo_1_1details_1_1optional_1a662eba2115a9b26930062f34dc88884b)`(const T & v) const` 

#### `typedef `[`value_type`](#classargo_1_1details_1_1optional_1a87fcf67ca38ce1f7f78e6747cb05b4c6) 

# class `argo::details::raii` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`raii`](#classargo_1_1details_1_1raii_1a9993793dacf336e8095de5bc78709322)`(const ConstructionCB on_construction,const DestructionCB on_destruction)` | 
`public  `[`raii`](#classargo_1_1details_1_1raii_1aa855bd9d8da9b0c7e0ca4c6b4180e1e4)`(const `[`raii`](#classargo_1_1details_1_1raii)` &) = delete` | 
`public `[`raii`](#classargo_1_1details_1_1raii)` & `[`operator=`](#classargo_1_1details_1_1raii_1a02ceeba638ccfd3075151bbfab5f032c)`(const `[`raii`](#classargo_1_1details_1_1raii)` &) = delete` | 
`public inline  `[`raii`](#classargo_1_1details_1_1raii_1a611d775b4798d85e8301e9b653d36368)`(`[`raii`](#classargo_1_1details_1_1raii)` && other)` | 
`public `[`raii`](#classargo_1_1details_1_1raii)` & `[`operator=`](#classargo_1_1details_1_1raii_1af4d71af357684bab8008ece3ccda2f6b)`(`[`raii`](#classargo_1_1details_1_1raii)` &&) = delete` | 
`public inline  `[`~raii`](#classargo_1_1details_1_1raii_1a43696854e4ea2f93fb62e31067606674)`()` | 

## Members

#### `public inline  explicit `[`raii`](#classargo_1_1details_1_1raii_1a9993793dacf336e8095de5bc78709322)`(const ConstructionCB on_construction,const DestructionCB on_destruction)` 

#### `public  `[`raii`](#classargo_1_1details_1_1raii_1aa855bd9d8da9b0c7e0ca4c6b4180e1e4)`(const `[`raii`](#classargo_1_1details_1_1raii)` &) = delete` 

#### `public `[`raii`](#classargo_1_1details_1_1raii)` & `[`operator=`](#classargo_1_1details_1_1raii_1a02ceeba638ccfd3075151bbfab5f032c)`(const `[`raii`](#classargo_1_1details_1_1raii)` &) = delete` 

#### `public inline  `[`raii`](#classargo_1_1details_1_1raii_1a611d775b4798d85e8301e9b653d36368)`(`[`raii`](#classargo_1_1details_1_1raii)` && other)` 

#### `public `[`raii`](#classargo_1_1details_1_1raii)` & `[`operator=`](#classargo_1_1details_1_1raii_1af4d71af357684bab8008ece3ccda2f6b)`(`[`raii`](#classargo_1_1details_1_1raii)` &&) = delete` 

#### `public inline  `[`~raii`](#classargo_1_1details_1_1raii_1a43696854e4ea2f93fb62e31067606674)`()` 

# class `argo::details::transform_iterator` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator_1aa4df69156b0e4f8fdc67e008d3b8e6b4)`(const transformation_type & f,It iterator)` | 
`public inline  explicit `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator_1a57ba23e3ef66d71422ae7b94086a23ca)`(It iterator)` | 
`public inline value_type `[`operator*`](#classargo_1_1details_1_1transform__iterator_1afc1ee2f38288b985fb6d94e83b60dfb9)`() const` | 
`public inline pointer `[`operator->`](#classargo_1_1details_1_1transform__iterator_1a4ea13ed1364af92aa4d73d9f8fb2e7b1)`() const` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator++`](#classargo_1_1details_1_1transform__iterator_1a20977d93e42f435ab5f88c28c6ce45f8)`()` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator++`](#classargo_1_1details_1_1transform__iterator_1aa3544be413984dd75c82cf3c34349016)`(int)` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator--`](#classargo_1_1details_1_1transform__iterator_1a3b4024445bfeebe97bf4325c13d62690)`()` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator--`](#classargo_1_1details_1_1transform__iterator_1ac1e8bf0092413cb9802a0a85f4818125)`(int)` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator+=`](#classargo_1_1details_1_1transform__iterator_1a5a6b6d539e263f54133d163f5dc60d2e)`(const unsigned int n)` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator-=`](#classargo_1_1details_1_1transform__iterator_1a1a0c33e86691722d0d2a04093f960f57)`(const unsigned int n)` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator+`](#classargo_1_1details_1_1transform__iterator_1a9d5b921421822b497a1b7b1edfe977be)`(const unsigned int n) const` | 
`public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator-`](#classargo_1_1details_1_1transform__iterator_1a0a8737113b79fbfa4ba71c5dd0f4c403)`(const unsigned int n) const` | 
`public inline difference_type `[`operator-`](#classargo_1_1details_1_1transform__iterator_1aec2cf8714ab4ed7e34e865d677e6509a)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` | 
`public inline bool `[`operator==`](#classargo_1_1details_1_1transform__iterator_1aa2bda37db8569a3d49eb920fd13bcfed)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` | 
`public inline bool `[`operator!=`](#classargo_1_1details_1_1transform__iterator_1ae69f1606958af52da7e118fa0c8fff0a)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` | 
`public inline bool `[`operator<`](#classargo_1_1details_1_1transform__iterator_1af4a2b24ce8282cbafa89b03c2db7aa19)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` | 
`public inline It `[`iterator`](#classargo_1_1details_1_1transform__iterator_1a5e9148535210cf0ae13220f7cba146ab)`() const` | 
`typedef `[`difference_type`](#classargo_1_1details_1_1transform__iterator_1a4434a92143ba0a9cad18a48bb86fb11d) | 
`typedef `[`value_type`](#classargo_1_1details_1_1transform__iterator_1a1a2561a6fc9cfef0c7d98239a042484b) | 
`typedef `[`pointer`](#classargo_1_1details_1_1transform__iterator_1a3f734d85ea2e91be26ade88084e71201) | 
`typedef `[`reference`](#classargo_1_1details_1_1transform__iterator_1a5623373c76927b95dc36a7a2e601a61f) | 
`typedef `[`iterator_category`](#classargo_1_1details_1_1transform__iterator_1a024752e793a15ac3903392651e864401) | 
`typedef `[`transformation_type`](#classargo_1_1details_1_1transform__iterator_1ae3418aec6a68aa17ce7975aa781d1f28) | 

## Members

#### `public inline  explicit `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator_1aa4df69156b0e4f8fdc67e008d3b8e6b4)`(const transformation_type & f,It iterator)` 

#### `public inline  explicit `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator_1a57ba23e3ef66d71422ae7b94086a23ca)`(It iterator)` 

#### `public inline value_type `[`operator*`](#classargo_1_1details_1_1transform__iterator_1afc1ee2f38288b985fb6d94e83b60dfb9)`() const` 

#### `public inline pointer `[`operator->`](#classargo_1_1details_1_1transform__iterator_1a4ea13ed1364af92aa4d73d9f8fb2e7b1)`() const` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator++`](#classargo_1_1details_1_1transform__iterator_1a20977d93e42f435ab5f88c28c6ce45f8)`()` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator++`](#classargo_1_1details_1_1transform__iterator_1aa3544be413984dd75c82cf3c34349016)`(int)` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator--`](#classargo_1_1details_1_1transform__iterator_1a3b4024445bfeebe97bf4325c13d62690)`()` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator--`](#classargo_1_1details_1_1transform__iterator_1ac1e8bf0092413cb9802a0a85f4818125)`(int)` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator+=`](#classargo_1_1details_1_1transform__iterator_1a5a6b6d539e263f54133d163f5dc60d2e)`(const unsigned int n)` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & `[`operator-=`](#classargo_1_1details_1_1transform__iterator_1a1a0c33e86691722d0d2a04093f960f57)`(const unsigned int n)` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator+`](#classargo_1_1details_1_1transform__iterator_1a9d5b921421822b497a1b7b1edfe977be)`(const unsigned int n) const` 

#### `public inline `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` `[`operator-`](#classargo_1_1details_1_1transform__iterator_1a0a8737113b79fbfa4ba71c5dd0f4c403)`(const unsigned int n) const` 

#### `public inline difference_type `[`operator-`](#classargo_1_1details_1_1transform__iterator_1aec2cf8714ab4ed7e34e865d677e6509a)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` 

#### `public inline bool `[`operator==`](#classargo_1_1details_1_1transform__iterator_1aa2bda37db8569a3d49eb920fd13bcfed)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` 

#### `public inline bool `[`operator!=`](#classargo_1_1details_1_1transform__iterator_1ae69f1606958af52da7e118fa0c8fff0a)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` 

#### `public inline bool `[`operator<`](#classargo_1_1details_1_1transform__iterator_1af4a2b24ce8282cbafa89b03c2db7aa19)`(const `[`transform_iterator`](#classargo_1_1details_1_1transform__iterator)` & other) const` 

#### `public inline It `[`iterator`](#classargo_1_1details_1_1transform__iterator_1a5e9148535210cf0ae13220f7cba146ab)`() const` 

#### `typedef `[`difference_type`](#classargo_1_1details_1_1transform__iterator_1a4434a92143ba0a9cad18a48bb86fb11d) 

#### `typedef `[`value_type`](#classargo_1_1details_1_1transform__iterator_1a1a2561a6fc9cfef0c7d98239a042484b) 

#### `typedef `[`pointer`](#classargo_1_1details_1_1transform__iterator_1a3f734d85ea2e91be26ade88084e71201) 

#### `typedef `[`reference`](#classargo_1_1details_1_1transform__iterator_1a5623373c76927b95dc36a7a2e601a61f) 

#### `typedef `[`iterator_category`](#classargo_1_1details_1_1transform__iterator_1a024752e793a15ac3903392651e864401) 

#### `typedef `[`transformation_type`](#classargo_1_1details_1_1transform__iterator_1ae3418aec6a68aa17ce7975aa781d1f28) 

# struct `argo::details::nullopt_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t_1a0599b2a3dd5b5d3cb9eb1f245abf6241)`(int)` | 

## Members

#### `public inline  `[`nullopt_t`](#structargo_1_1details_1_1nullopt__t_1a0599b2a3dd5b5d3cb9eb1f245abf6241)`(int)` 

# namespace `argo::details::string` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`std::string `[`join`](#_argo_8hpp_1a83aab82db1600bbf5fa492e0c8c8ba6e)`(It begin,It end,const std::string & separator)`            | 
`public template<>`  <br/>`std::string `[`join`](#_argo_8hpp_1aa51411f3cf16c9008898cbbf1f5cbb49)`(const std::initializer_list< T > & list,const std::string & separator)`            | 
`public inline std::vector< std::string > `[`split`](#_argo_8hpp_1ae1814939ed8431a36f9e6a0f9b2af7b7)`(std::string str,std::string delimiter)`            | 
`public inline void `[`replace_all`](#_argo_8hpp_1a5f52fc20b1507baba98b36e3aee242c1)`(std::string & str,const std::string & from,const std::string & to)`            | 
`public inline bool `[`starts_with`](#_argo_8hpp_1a86c988a0fe7ada916f0f5fd70ceaac88)`(const std::string & input,const std::string & test)`            | 
`public inline bool `[`ends_with`](#_argo_8hpp_1a1f75d1d94b1d30ccffcc82fccd19b31f)`(const std::string & input,const std::string & test)`            | 
`public inline void `[`ltrim`](#_argo_8hpp_1a6aba62a6267b5a4c85beb32e3c238666)`(std::string & input)`            | 
`public inline void `[`rtrim`](#_argo_8hpp_1a6200a58de295bb29755a710e419cbc55)`(std::string & input)`            | 
`public inline void `[`trim`](#_argo_8hpp_1a3707b9e3ee900298e422eb05dd4be7f3)`(std::string & input)`            | 
`public inline std::string `[`surround`](#_argo_8hpp_1a1886cd2a011eddb6fddbf3753ce08159)`(const std::string & input,const std::string & left,`[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > right)`            | 
`public template<>`  <br/>`void `[`split`](#_argo_8hpp_1a2b117d3811a0f127fe44deb0ba134e2e)`(const std::string & input,const char delimiter,Out out)`            | 
`public inline std::vector< std::string > `[`split`](#_argo_8hpp_1ae3b5b34b17cddd1d33e4bfccf16c153b)`(const std::string & input,const char delimiter)`            | 
`class `[`argo::details::string::Text`](#classargo_1_1details_1_1string_1_1_text) | 
`struct `[`argo::details::string::from`](#structargo_1_1details_1_1string_1_1from) | 
`struct `[`argo::details::string::from< const char * >`](#structargo_1_1details_1_1string_1_1from_3_01const_01char_01_5_01_4) | 
`struct `[`argo::details::string::from< std::string >`](#structargo_1_1details_1_1string_1_1from_3_01std_1_1string_01_4) | 

## Members

#### `public template<>`  <br/>`std::string `[`join`](#_argo_8hpp_1a83aab82db1600bbf5fa492e0c8c8ba6e)`(It begin,It end,const std::string & separator)` 

#### `public template<>`  <br/>`std::string `[`join`](#_argo_8hpp_1aa51411f3cf16c9008898cbbf1f5cbb49)`(const std::initializer_list< T > & list,const std::string & separator)` 

#### `public inline std::vector< std::string > `[`split`](#_argo_8hpp_1ae1814939ed8431a36f9e6a0f9b2af7b7)`(std::string str,std::string delimiter)` 

#### `public inline void `[`replace_all`](#_argo_8hpp_1a5f52fc20b1507baba98b36e3aee242c1)`(std::string & str,const std::string & from,const std::string & to)` 

#### `public inline bool `[`starts_with`](#_argo_8hpp_1a86c988a0fe7ada916f0f5fd70ceaac88)`(const std::string & input,const std::string & test)` 

#### `public inline bool `[`ends_with`](#_argo_8hpp_1a1f75d1d94b1d30ccffcc82fccd19b31f)`(const std::string & input,const std::string & test)` 

#### `public inline void `[`ltrim`](#_argo_8hpp_1a6aba62a6267b5a4c85beb32e3c238666)`(std::string & input)` 

#### `public inline void `[`rtrim`](#_argo_8hpp_1a6200a58de295bb29755a710e419cbc55)`(std::string & input)` 

#### `public inline void `[`trim`](#_argo_8hpp_1a3707b9e3ee900298e422eb05dd4be7f3)`(std::string & input)` 

#### `public inline std::string `[`surround`](#_argo_8hpp_1a1886cd2a011eddb6fddbf3753ce08159)`(const std::string & input,const std::string & left,`[`details::optional`](#classargo_1_1details_1_1optional)`< std::string > right)` 

#### `public template<>`  <br/>`void `[`split`](#_argo_8hpp_1a2b117d3811a0f127fe44deb0ba134e2e)`(const std::string & input,const char delimiter,Out out)` 

#### `public inline std::vector< std::string > `[`split`](#_argo_8hpp_1ae3b5b34b17cddd1d33e4bfccf16c153b)`(const std::string & input,const char delimiter)` 

# class `argo::details::string::Text` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1ab699b6d5f0a91d182d627b8d2834aa64)`(const T & element)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1aa7fc7c28950645a22bae81ff53bd234a)`(std::string str)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a862302d452b86ce800455e48029b0543)`(const Endline & tag)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a975b268d69f380f52f1d62436236b01f)`(const Indent & tag)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a87433c537c66e14a42ff6feb232c66f2)`(const Outdent & tag)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a3a5bec389704e9796d777aff59b8fbbe)`(const Boolalpha & tag)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a38eb75f79f54eb327aaba1ce97c815a6)`(const `[`Color::Code`](#structargo_1_1details_1_1string_1_1_text_1_1_color_1_1_code)` & tag)` | 
`public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a59a6e04cb0766ea3ed7002bbf132a744)`(const `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & txt)` | 
`public inline std::string `[`str`](#classargo_1_1details_1_1string_1_1_text_1a3699dad41d6625cb468129925e0de006)`() const` | 
`public inline void `[`clear`](#classargo_1_1details_1_1string_1_1_text_1a6c7b69350eb31c3ca80128bbe59400d1)`()` | 

## Members

#### `public template<>`  <br/>[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1ab699b6d5f0a91d182d627b8d2834aa64)`(const T & element)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1aa7fc7c28950645a22bae81ff53bd234a)`(std::string str)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a862302d452b86ce800455e48029b0543)`(const Endline & tag)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a975b268d69f380f52f1d62436236b01f)`(const Indent & tag)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a87433c537c66e14a42ff6feb232c66f2)`(const Outdent & tag)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a3a5bec389704e9796d777aff59b8fbbe)`(const Boolalpha & tag)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a38eb75f79f54eb327aaba1ce97c815a6)`(const `[`Color::Code`](#structargo_1_1details_1_1string_1_1_text_1_1_color_1_1_code)` & tag)` 

#### `public inline `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & `[`operator<<`](#classargo_1_1details_1_1string_1_1_text_1a59a6e04cb0766ea3ed7002bbf132a744)`(const `[`Text`](#classargo_1_1details_1_1string_1_1_text)` & txt)` 

#### `public inline std::string `[`str`](#classargo_1_1details_1_1string_1_1_text_1a3699dad41d6625cb468129925e0de006)`() const` 

#### `public inline void `[`clear`](#classargo_1_1details_1_1string_1_1_text_1a6c7b69350eb31c3ca80128bbe59400d1)`()` 

# struct `argo::details::string::from` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::from< const char * >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::from< std::string >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# namespace `argo::details::transformation` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`argo::details::transformation::dereference`](#structargo_1_1details_1_1transformation_1_1dereference) | 
`struct `[`argo::details::transformation::dereference_mapped_type`](#structargo_1_1details_1_1transformation_1_1dereference__mapped__type) | 
`struct `[`argo::details::transformation::mapped_type`](#structargo_1_1details_1_1transformation_1_1mapped__type) | 

# struct `argo::details::transformation::dereference` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1dereference_1adaf606ea6f7d581addb309d6ac7a1a22)`(It it) const` | 

## Members

#### `public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1dereference_1adaf606ea6f7d581addb309d6ac7a1a22)`(It it) const` 

# struct `argo::details::transformation::dereference_mapped_type` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1dereference__mapped__type_1accd1848bbc4237bc6c6df0607a953d7c)`(It it) const` | 

## Members

#### `public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1dereference__mapped__type_1accd1848bbc4237bc6c6df0607a953d7c)`(It it) const` 

# struct `argo::details::transformation::mapped_type` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1mapped__type_1afd8a3fe6e39864a4df4b0bdcf9a3e448)`(It it) const` | 

## Members

#### `public template<>`  <br/>`inline ReturnType `[`operator()`](#structargo_1_1details_1_1transformation_1_1mapped__type_1afd8a3fe6e39864a4df4b0bdcf9a3e448)`(It it) const` 

# namespace `argo::formatter` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::string `[`format`](#_argo_8hpp_1aa678b64a094d588dcf45027f669a1701)`(const std::string & text,const unsigned int width,const unsigned int left_margin)`            | 
`class `[`argo::formatter::Default`](#classargo_1_1formatter_1_1_default) | 
`class `[`argo::formatter::IFormatter`](#classargo_1_1formatter_1_1_i_formatter) | Formatter interface. The convention is for all output to end with a newline, except for.

## Members

#### `public inline std::string `[`format`](#_argo_8hpp_1aa678b64a094d588dcf45027f669a1701)`(const std::string & text,const unsigned int width,const unsigned int left_margin)` 

# class `argo::formatter::Default` 

```
class argo::formatter::Default
  : public argo::formatter::IFormatter
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Default`](#classargo_1_1formatter_1_1_default_1a6af81e181b8b60d2ce0b986fd55f7502)`()` | 
`public inline virtual std::string `[`format_error`](#classargo_1_1formatter_1_1_default_1a30cec576731bc4f947c4c76d0cbf9ee9)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & message)` | 
`public inline virtual std::string `[`format_help`](#classargo_1_1formatter_1_1_default_1a4e39a4c0ca6de21f004fd392125d0264)`(`[`Context`](#classargo_1_1_context)` & context)` | 
`public inline virtual std::string `[`format_version`](#classargo_1_1formatter_1_1_default_1a63abbc60f9f81128aa05fb8d964511e8)`(`[`Context`](#classargo_1_1_context)` & context)` | 

## Members

#### `public inline  `[`Default`](#classargo_1_1formatter_1_1_default_1a6af81e181b8b60d2ce0b986fd55f7502)`()` 

#### `public inline virtual std::string `[`format_error`](#classargo_1_1formatter_1_1_default_1a30cec576731bc4f947c4c76d0cbf9ee9)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & message)` 

#### `public inline virtual std::string `[`format_help`](#classargo_1_1formatter_1_1_default_1a4e39a4c0ca6de21f004fd392125d0264)`(`[`Context`](#classargo_1_1_context)` & context)` 

#### `public inline virtual std::string `[`format_version`](#classargo_1_1formatter_1_1_default_1a63abbc60f9f81128aa05fb8d964511e8)`(`[`Context`](#classargo_1_1_context)` & context)` 

# class `argo::formatter::IFormatter` 

Formatter interface. The convention is for all output to end with a newline, except for.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`IFormatter`](#classargo_1_1formatter_1_1_i_formatter_1a84c54458836caa9ceb695c69f1688428)`() = default` | 
`public virtual  `[`~IFormatter`](#classargo_1_1formatter_1_1_i_formatter_1a4087e473951b4904d140112124d03956)`() = default` | 
`public std::string `[`format_error`](#classargo_1_1formatter_1_1_i_formatter_1a02e0cfa21bde16550e7363c89442582e)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & message)` | 
`public std::string `[`format_help`](#classargo_1_1formatter_1_1_i_formatter_1aef38225931f152c4e86462d3a828f70f)`(`[`Context`](#classargo_1_1_context)` & context)` | 
`public std::string `[`format_version`](#classargo_1_1formatter_1_1_i_formatter_1a5585413e2dbe77c6ea2b2c46e0aec0fe)`(`[`Context`](#classargo_1_1_context)` & context)` | 

## Members

#### `public  explicit `[`IFormatter`](#classargo_1_1formatter_1_1_i_formatter_1a84c54458836caa9ceb695c69f1688428)`() = default` 

#### `public virtual  `[`~IFormatter`](#classargo_1_1formatter_1_1_i_formatter_1a4087e473951b4904d140112124d03956)`() = default` 

#### `public std::string `[`format_error`](#classargo_1_1formatter_1_1_i_formatter_1a02e0cfa21bde16550e7363c89442582e)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & message)` 

#### `public std::string `[`format_help`](#classargo_1_1formatter_1_1_i_formatter_1aef38225931f152c4e86462d3a828f70f)`(`[`Context`](#classargo_1_1_context)` & context)` 

#### `public std::string `[`format_version`](#classargo_1_1formatter_1_1_i_formatter_1a5585413e2dbe77c6ea2b2c46e0aec0fe)`(`[`Context`](#classargo_1_1_context)` & context)` 

# namespace `argo::handler` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`Confidence`](#_argo_8hpp_1a66163b0c4def95f3eca3b89426114484)            | 
`public inline std::ostream & `[`operator<<`](#_argo_8hpp_1a7a41a78349066d081624d0de5101738d)`(std::ostream & os,const `[`Option`](#classargo_1_1handler_1_1_option)` & option)`            | 
`class `[`argo::handler::IHandler`](#classargo_1_1handler_1_1_i_handler) | 
`class `[`argo::handler::Option`](#classargo_1_1handler_1_1_option) | Options are the final handlers of arguments.

## Members

#### `enum `[`Confidence`](#_argo_8hpp_1a66163b0c4def95f3eca3b89426114484) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
Zero            | 
Maybe            | 
Definitely            | 

#### `public inline std::ostream & `[`operator<<`](#_argo_8hpp_1a7a41a78349066d081624d0de5101738d)`(std::ostream & os,const `[`Option`](#classargo_1_1handler_1_1_option)` & option)` 

# class `argo::handler::IHandler` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~IHandler`](#classargo_1_1handler_1_1_i_handler_1af8ed2f59aa3c80705514ec744fa97bcc)`() = default` | 
`public inline unsigned int `[`nr_selected`](#classargo_1_1handler_1_1_i_handler_1a6ce078b594067e4b7103862e8ec96cc4)`() const` | 
`public inline bool `[`can_handle`](#classargo_1_1handler_1_1_i_handler_1afc9cd94d387a0a5fabcb39ececd84443)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | 
`public Ptr `[`clone`](#classargo_1_1handler_1_1_i_handler_1a4ff8d963c0005aac4914a31f13b41bde)`() const` | 
`public bool `[`is_valid`](#classargo_1_1handler_1_1_i_handler_1ac7aec2c039f92bc5466d5d9785c80982)`() const` | Returns whether the handler has been correctly configured by the user.
`public std::string `[`hash`](#classargo_1_1handler_1_1_i_handler_1ab914c8f685f948974d4f9a73b4edc4c3)`() const` | 
`public bool `[`recognizes`](#classargo_1_1handler_1_1_i_handler_1a4654f15cad1d664b66546fa3f4076054)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | Returns whether the handler recognizes the raw argument. If it does, it is required.
`public bool `[`is_satisfied`](#classargo_1_1handler_1_1_i_handler_1adaa62b6895f2a36de04de41639a148ff)`(`[`Context`](#classargo_1_1_context)` & context) const` | Returns whether the handler is satisfied: has it been able to fulfill its configuration.
`protected unsigned int `[`nr_selected_`](#classargo_1_1handler_1_1_i_handler_1a2f6cd0aaca4192c43e0334d4976b15b1) | 

## Members

#### `public virtual  `[`~IHandler`](#classargo_1_1handler_1_1_i_handler_1af8ed2f59aa3c80705514ec744fa97bcc)`() = default` 

#### `public inline unsigned int `[`nr_selected`](#classargo_1_1handler_1_1_i_handler_1a6ce078b594067e4b7103862e8ec96cc4)`() const` 

#### `public inline bool `[`can_handle`](#classargo_1_1handler_1_1_i_handler_1afc9cd94d387a0a5fabcb39ececd84443)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

#### `public Ptr `[`clone`](#classargo_1_1handler_1_1_i_handler_1a4ff8d963c0005aac4914a31f13b41bde)`() const` 

#### `public bool `[`is_valid`](#classargo_1_1handler_1_1_i_handler_1ac7aec2c039f92bc5466d5d9785c80982)`() const` 

Returns whether the handler has been correctly configured by the user.

#### `public std::string `[`hash`](#classargo_1_1handler_1_1_i_handler_1ab914c8f685f948974d4f9a73b4edc4c3)`() const` 

#### `public bool `[`recognizes`](#classargo_1_1handler_1_1_i_handler_1a4654f15cad1d664b66546fa3f4076054)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

Returns whether the handler recognizes the raw argument. If it does, it is required.

#### `public bool `[`is_satisfied`](#classargo_1_1handler_1_1_i_handler_1adaa62b6895f2a36de04de41639a148ff)`(`[`Context`](#classargo_1_1_context)` & context) const` 

Returns whether the handler is satisfied: has it been able to fulfill its configuration.

#### `protected unsigned int `[`nr_selected_`](#classargo_1_1handler_1_1_i_handler_1a2f6cd0aaca4192c43e0334d4976b15b1) 

# class `argo::handler::Option` 

```
class argo::handler::Option
  : public argo::handler::IHandler
```  

Options are the final handlers of arguments.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Option`](#classargo_1_1handler_1_1_option_1aa75ddf370e2f1fd25c72da816c2046c4)`(const std::string & shorthand,const std::string & longhand)` | 
`public inline  explicit `[`Option`](#classargo_1_1handler_1_1_option_1a9367fd0302a48949bbee7e085a8b7f0e)`(const std::string & short_or_longhand)` | 
`public inline `[`Name`](#structargo_1_1_name)` `[`name`](#classargo_1_1handler_1_1_option_1af178a2e65ed7b0ec03b6971b0c4b1a59)`() const` | 
`public inline const std::vector< action::Ptr > & `[`actions`](#classargo_1_1handler_1_1_option_1ad7489c2bcb4041beccb44f916fa85702)`() const` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`action`](#classargo_1_1handler_1_1_option_1a81e7f838b66dd9923056a476f59c0ce9)`(const `[`action::IAction`](#classargo_1_1action_1_1_i_action)` & action)` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1a4ed4e8fe18e18e1667137c4c184324ea)`(nargs::Ptr && ptr)` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1a567439b91156adcaf8abb0338eb8f087)`(const unsigned int count)` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1acecfed4b802dec8cb655a96c099ccf4d)`(const std::string & type)` | 
`public inline const `[`nargs::INargs`](#classargo_1_1nargs_1_1_i_nargs)` & `[`nargs`](#classargo_1_1handler_1_1_option_1acc0a85329784fc88af1ebea5fa305e94)`() const` | 
`public inline `[`nargs::INargs`](#classargo_1_1nargs_1_1_i_nargs)` & `[`nargs`](#classargo_1_1handler_1_1_option_1ad45b25bd9f671d67a42e0d0673579df3)`()` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1handler_1_1_option_1a9a59202f291daf1b715435811bed3f69)`(const bool state)` | 
`public inline std::string `[`help`](#classargo_1_1handler_1_1_option_1ac70f48709e79100d735ef1e9f679697e)`() const` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`help`](#classargo_1_1handler_1_1_option_1a8aaeadf8769853334c15c51b5730d569)`(const std::string & description)` | 
`public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`required`](#classargo_1_1handler_1_1_option_1ad8e2833cc365e700f7a0e73b0be032fd)`(const bool state)` | 
`public inline bool `[`is_required`](#classargo_1_1handler_1_1_option_1a0634a87526c25272b8324caff0012003)`() const` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1_option_1aa04b4168cdc041464d9d919aac9529f8)`() const` | 
`public inline virtual bool `[`is_valid`](#classargo_1_1handler_1_1_option_1a2dd04646556051238b7b24bb51f6c80e)`() const` | Returns whether the handler has been correctly configured by the user.
`public inline virtual std::string `[`hash`](#classargo_1_1handler_1_1_option_1a0a86f8dc7f058b832c5978a823e76e3e)`() const` | 
`public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1_option_1a070b7ee6413dfba7bd74948ca42e9404)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | Returns whether the handler recognizes the raw argument. If it does, it is required.
`public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1_option_1ac606a8a5d8394132ae1b9dce8e4f007f)`(`[`Context`](#classargo_1_1_context)` & context) const` | Returns whether the handler is satisfied: has it been able to fulfill its configuration.
`public inline bool `[`process`](#classargo_1_1handler_1_1_option_1a21cdaa7eadc2b43f5730ed21bc707e9d)`(`[`Context`](#classargo_1_1_context)` & context,RawList::iterator & current,RawList::iterator end)` | 

## Members

#### `public inline  explicit `[`Option`](#classargo_1_1handler_1_1_option_1aa75ddf370e2f1fd25c72da816c2046c4)`(const std::string & shorthand,const std::string & longhand)` 

#### `public inline  explicit `[`Option`](#classargo_1_1handler_1_1_option_1a9367fd0302a48949bbee7e085a8b7f0e)`(const std::string & short_or_longhand)` 

#### `public inline `[`Name`](#structargo_1_1_name)` `[`name`](#classargo_1_1handler_1_1_option_1af178a2e65ed7b0ec03b6971b0c4b1a59)`() const` 

#### `public inline const std::vector< action::Ptr > & `[`actions`](#classargo_1_1handler_1_1_option_1ad7489c2bcb4041beccb44f916fa85702)`() const` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`action`](#classargo_1_1handler_1_1_option_1a81e7f838b66dd9923056a476f59c0ce9)`(const `[`action::IAction`](#classargo_1_1action_1_1_i_action)` & action)` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1a4ed4e8fe18e18e1667137c4c184324ea)`(nargs::Ptr && ptr)` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1a567439b91156adcaf8abb0338eb8f087)`(const unsigned int count)` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`nargs`](#classargo_1_1handler_1_1_option_1acecfed4b802dec8cb655a96c099ccf4d)`(const std::string & type)` 

#### `public inline const `[`nargs::INargs`](#classargo_1_1nargs_1_1_i_nargs)` & `[`nargs`](#classargo_1_1handler_1_1_option_1acc0a85329784fc88af1ebea5fa305e94)`() const` 

#### `public inline `[`nargs::INargs`](#classargo_1_1nargs_1_1_i_nargs)` & `[`nargs`](#classargo_1_1handler_1_1_option_1ad45b25bd9f671d67a42e0d0673579df3)`()` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1handler_1_1_option_1a9a59202f291daf1b715435811bed3f69)`(const bool state)` 

#### `public inline std::string `[`help`](#classargo_1_1handler_1_1_option_1ac70f48709e79100d735ef1e9f679697e)`() const` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`help`](#classargo_1_1handler_1_1_option_1a8aaeadf8769853334c15c51b5730d569)`(const std::string & description)` 

#### `public inline `[`Option`](#classargo_1_1handler_1_1_option)` & `[`required`](#classargo_1_1handler_1_1_option_1ad8e2833cc365e700f7a0e73b0be032fd)`(const bool state)` 

#### `public inline bool `[`is_required`](#classargo_1_1handler_1_1_option_1a0634a87526c25272b8324caff0012003)`() const` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1_option_1aa04b4168cdc041464d9d919aac9529f8)`() const` 

#### `public inline virtual bool `[`is_valid`](#classargo_1_1handler_1_1_option_1a2dd04646556051238b7b24bb51f6c80e)`() const` 

Returns whether the handler has been correctly configured by the user.

#### `public inline virtual std::string `[`hash`](#classargo_1_1handler_1_1_option_1a0a86f8dc7f058b832c5978a823e76e3e)`() const` 

#### `public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1_option_1a070b7ee6413dfba7bd74948ca42e9404)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

Returns whether the handler recognizes the raw argument. If it does, it is required.

#### `public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1_option_1ac606a8a5d8394132ae1b9dce8e4f007f)`(`[`Context`](#classargo_1_1_context)` & context) const` 

Returns whether the handler is satisfied: has it been able to fulfill its configuration.

#### `public inline bool `[`process`](#classargo_1_1handler_1_1_option_1a21cdaa7eadc2b43f5730ed21bc707e9d)`(`[`Context`](#classargo_1_1_context)` & context,RawList::iterator & current,RawList::iterator end)` 

# namespace `argo::handler::group` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`argo::handler::group::Exclusive`](#classargo_1_1handler_1_1group_1_1_exclusive) | [Exclusive](#classargo_1_1handler_1_1group_1_1_exclusive) groups: the presence of any one option/group within it, excludes the presence of the others.
`class `[`argo::handler::group::IGroup`](#classargo_1_1handler_1_1group_1_1_i_group) | Base class of group handlers.
`class `[`argo::handler::group::Inclusive`](#classargo_1_1handler_1_1group_1_1_inclusive) | [Inclusive](#classargo_1_1handler_1_1group_1_1_inclusive) groups: the presence of any one option/group within it, forces the presence of the others.
`class `[`argo::handler::group::Plain`](#classargo_1_1handler_1_1group_1_1_plain) | Group that merely serves as a collection of options, with no additional properties.

# class `argo::handler::group::Exclusive` 

```
class argo::handler::group::Exclusive
  : public argo::handler::group::IGroup
```  

[Exclusive](#classargo_1_1handler_1_1group_1_1_exclusive) groups: the presence of any one option/group within it, excludes the presence of the others.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Exclusive`](#classargo_1_1handler_1_1group_1_1_exclusive_1ac64f8e82e04a0d23549dc33985d37886)`(const std::string & group_name)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_exclusive_1acf9c89a52911bd60673575eab8c640d9)`() const` | 
`public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_exclusive_1ac369c2e0cf6f24a7a4810d65d7d29cca)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | Returns whether the handler recognizes the raw argument. If it does, it is required.
`public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_exclusive_1a32195a86ea5d1dd2ec99d24d4051074a)`() const` | 

## Members

#### `public inline  explicit `[`Exclusive`](#classargo_1_1handler_1_1group_1_1_exclusive_1ac64f8e82e04a0d23549dc33985d37886)`(const std::string & group_name)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_exclusive_1acf9c89a52911bd60673575eab8c640d9)`() const` 

#### `public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_exclusive_1ac369c2e0cf6f24a7a4810d65d7d29cca)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

Returns whether the handler recognizes the raw argument. If it does, it is required.

#### `public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_exclusive_1a32195a86ea5d1dd2ec99d24d4051074a)`() const` 

# class `argo::handler::group::IGroup` 

```
class argo::handler::group::IGroup
  : public argo::handler::IHandler
```  

Base class of group handlers.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group_1a2003a5cff7b9daadcdb89899a714a93b)`(const std::string & name)` | 
`public inline virtual bool `[`is_valid`](#classargo_1_1handler_1_1group_1_1_i_group_1aa48037e83970290d64da7b1ca4fcc734)`() const` | Returns whether the handler has been correctly configured by the user.
`public inline virtual std::string `[`hash`](#classargo_1_1handler_1_1group_1_1_i_group_1a6b75ec7d67ca5e9afe477b7787e7f861)`() const` | 
`public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1group_1_1_i_group_1af4343fea3418168d7f4751f9f81e376c)`(`[`Context`](#classargo_1_1_context)` & context) const` | Returns whether the handler is satisfied: has it been able to fulfill its configuration.
`public inline std::string `[`name`](#classargo_1_1handler_1_1group_1_1_i_group_1a0ab71df84fababa787225302bf72268a)`() const` | 
`public inline bool `[`empty`](#classargo_1_1handler_1_1group_1_1_i_group_1a4dc87c8c3c2faec999dd4e5d7d5cf220)`() const` | 
`public inline std::size_t `[`size`](#classargo_1_1handler_1_1group_1_1_i_group_1aa940be507fac057581305864d50562ea)`() const` | 
`public inline bool `[`add`](#classargo_1_1handler_1_1group_1_1_i_group_1ad503dd6667643b7d58e93da04522b474)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` | 
`public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1handler_1_1group_1_1_i_group_1aa8e08778266c70ccc4fec4ed45af04b2)`(Args &&... args)` | 
`public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1handler_1_1group_1_1_i_group_1acfab1811211ce5fb26f623a8e22dea5a)`(Args &&... args)` | 
`public inline `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` & `[`help`](#classargo_1_1handler_1_1group_1_1_i_group_1a818d295afb14e605fcab9a889ea379a9)`(const std::string & description)` | 
`public inline std::string `[`help`](#classargo_1_1handler_1_1group_1_1_i_group_1a5cb6dd5bbcbf314c2ecdb4bc3a395266)`() const` | 
`public inline `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` & `[`required`](#classargo_1_1handler_1_1group_1_1_i_group_1a62094d18b9046ee9d5013a1002c72aa9)`(const bool state)` | 
`public inline bool `[`is_required`](#classargo_1_1handler_1_1group_1_1_i_group_1a95dc7a9163daa50693919ffd2286d06a)`() const` | 
`public inline const `[`Handlers`](#classargo_1_1_handlers)` & `[`handlers`](#classargo_1_1handler_1_1group_1_1_i_group_1abe5861a19d964febdc65850a80438a10)`() const` | 
`public std::string `[`description`](#classargo_1_1handler_1_1group_1_1_i_group_1a3e453955bbf36a970fa5d2b66d89cac8)`() const` | 
`protected std::string `[`name_`](#classargo_1_1handler_1_1group_1_1_i_group_1a9b12cdf8dd671886773b890fc02d8b12) | 
`protected mutable std::string `[`hash_`](#classargo_1_1handler_1_1group_1_1_i_group_1a3f9dd300318d9bb46004b2715f333cfe) | 
`protected std::string `[`help_`](#classargo_1_1handler_1_1group_1_1_i_group_1a0eb2797f7ca3e5aba2b04b48a885d55c) | 
`protected bool `[`is_required_`](#classargo_1_1handler_1_1group_1_1_i_group_1af901c628de3669b179bc22ebea58eadc) | 
`protected `[`Handlers`](#classargo_1_1_handlers)` `[`handlers_`](#classargo_1_1handler_1_1group_1_1_i_group_1a99a4b9e2da986d54a7b676d1ec5d6892) | 

## Members

#### `public inline  explicit `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group_1a2003a5cff7b9daadcdb89899a714a93b)`(const std::string & name)` 

#### `public inline virtual bool `[`is_valid`](#classargo_1_1handler_1_1group_1_1_i_group_1aa48037e83970290d64da7b1ca4fcc734)`() const` 

Returns whether the handler has been correctly configured by the user.

#### `public inline virtual std::string `[`hash`](#classargo_1_1handler_1_1group_1_1_i_group_1a6b75ec7d67ca5e9afe477b7787e7f861)`() const` 

#### `public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1group_1_1_i_group_1af4343fea3418168d7f4751f9f81e376c)`(`[`Context`](#classargo_1_1_context)` & context) const` 

Returns whether the handler is satisfied: has it been able to fulfill its configuration.

#### `public inline std::string `[`name`](#classargo_1_1handler_1_1group_1_1_i_group_1a0ab71df84fababa787225302bf72268a)`() const` 

#### `public inline bool `[`empty`](#classargo_1_1handler_1_1group_1_1_i_group_1a4dc87c8c3c2faec999dd4e5d7d5cf220)`() const` 

#### `public inline std::size_t `[`size`](#classargo_1_1handler_1_1group_1_1_i_group_1aa940be507fac057581305864d50562ea)`() const` 

#### `public inline bool `[`add`](#classargo_1_1handler_1_1group_1_1_i_group_1ad503dd6667643b7d58e93da04522b474)`(const `[`handler::IHandler`](#classargo_1_1handler_1_1_i_handler)` & handler)` 

#### `public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`option`](#classargo_1_1handler_1_1group_1_1_i_group_1aa8e08778266c70ccc4fec4ed45af04b2)`(Args &&... args)` 

#### `public template<>`  <br/>`inline `[`handler::Option`](#classargo_1_1handler_1_1_option)` & `[`toggle`](#classargo_1_1handler_1_1group_1_1_i_group_1acfab1811211ce5fb26f623a8e22dea5a)`(Args &&... args)` 

#### `public inline `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` & `[`help`](#classargo_1_1handler_1_1group_1_1_i_group_1a818d295afb14e605fcab9a889ea379a9)`(const std::string & description)` 

#### `public inline std::string `[`help`](#classargo_1_1handler_1_1group_1_1_i_group_1a5cb6dd5bbcbf314c2ecdb4bc3a395266)`() const` 

#### `public inline `[`IGroup`](#classargo_1_1handler_1_1group_1_1_i_group)` & `[`required`](#classargo_1_1handler_1_1group_1_1_i_group_1a62094d18b9046ee9d5013a1002c72aa9)`(const bool state)` 

#### `public inline bool `[`is_required`](#classargo_1_1handler_1_1group_1_1_i_group_1a95dc7a9163daa50693919ffd2286d06a)`() const` 

#### `public inline const `[`Handlers`](#classargo_1_1_handlers)` & `[`handlers`](#classargo_1_1handler_1_1group_1_1_i_group_1abe5861a19d964febdc65850a80438a10)`() const` 

#### `public std::string `[`description`](#classargo_1_1handler_1_1group_1_1_i_group_1a3e453955bbf36a970fa5d2b66d89cac8)`() const` 

#### `protected std::string `[`name_`](#classargo_1_1handler_1_1group_1_1_i_group_1a9b12cdf8dd671886773b890fc02d8b12) 

#### `protected mutable std::string `[`hash_`](#classargo_1_1handler_1_1group_1_1_i_group_1a3f9dd300318d9bb46004b2715f333cfe) 

#### `protected std::string `[`help_`](#classargo_1_1handler_1_1group_1_1_i_group_1a0eb2797f7ca3e5aba2b04b48a885d55c) 

#### `protected bool `[`is_required_`](#classargo_1_1handler_1_1group_1_1_i_group_1af901c628de3669b179bc22ebea58eadc) 

#### `protected `[`Handlers`](#classargo_1_1_handlers)` `[`handlers_`](#classargo_1_1handler_1_1group_1_1_i_group_1a99a4b9e2da986d54a7b676d1ec5d6892) 

# class `argo::handler::group::Inclusive` 

```
class argo::handler::group::Inclusive
  : public argo::handler::group::IGroup
```  

[Inclusive](#classargo_1_1handler_1_1group_1_1_inclusive) groups: the presence of any one option/group within it, forces the presence of the others.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Inclusive`](#classargo_1_1handler_1_1group_1_1_inclusive_1a9f0ffd09dfb1f46616e40541013a18b5)`(const std::string & group_name)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_inclusive_1ad7c3b65b7d40ba2f6d1d01bd5c9bcae9)`() const` | 
`public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_inclusive_1a3561eaa00c79defcd57366859b77ab79)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | Returns whether the handler recognizes the raw argument. If it does, it is required.
`public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1group_1_1_inclusive_1ad964c2df3d9079fa99bfb2c7367f070b)`(`[`Context`](#classargo_1_1_context)` & context) const` | Returns whether the handler is satisfied: has it been able to fulfill its configuration.
`public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_inclusive_1aaaaae4844b61e73db116f2b95975ba8b)`() const` | 

## Members

#### `public inline  explicit `[`Inclusive`](#classargo_1_1handler_1_1group_1_1_inclusive_1a9f0ffd09dfb1f46616e40541013a18b5)`(const std::string & group_name)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_inclusive_1ad7c3b65b7d40ba2f6d1d01bd5c9bcae9)`() const` 

#### `public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_inclusive_1a3561eaa00c79defcd57366859b77ab79)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

Returns whether the handler recognizes the raw argument. If it does, it is required.

#### `public inline virtual bool `[`is_satisfied`](#classargo_1_1handler_1_1group_1_1_inclusive_1ad964c2df3d9079fa99bfb2c7367f070b)`(`[`Context`](#classargo_1_1_context)` & context) const` 

Returns whether the handler is satisfied: has it been able to fulfill its configuration.

#### `public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_inclusive_1aaaaae4844b61e73db116f2b95975ba8b)`() const` 

# class `argo::handler::group::Plain` 

```
class argo::handler::group::Plain
  : public argo::handler::group::IGroup
```  

Group that merely serves as a collection of options, with no additional properties.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`Plain`](#classargo_1_1handler_1_1group_1_1_plain_1aa832d3e9f06040ff84d25ba88e6988d0)`(const std::string & group_name)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_plain_1a10e6b1240202a1530ccbd29a8f2316b6)`() const` | 
`public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_plain_1a3dac4b65bff12aae498f78210aa41b00)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` | Returns whether the handler recognizes the raw argument. If it does, it is required.
`public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_plain_1af578ffc014b9ebd14157cde4364b986c)`() const` | 

## Members

#### `public inline  explicit `[`Plain`](#classargo_1_1handler_1_1group_1_1_plain_1aa832d3e9f06040ff84d25ba88e6988d0)`(const std::string & group_name)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1handler_1_1group_1_1_plain_1a10e6b1240202a1530ccbd29a8f2316b6)`() const` 

#### `public inline virtual bool `[`recognizes`](#classargo_1_1handler_1_1group_1_1_plain_1a3dac4b65bff12aae498f78210aa41b00)`(`[`Context`](#classargo_1_1_context)` & context,const std::string & raw_arg)` 

Returns whether the handler recognizes the raw argument. If it does, it is required.

#### `public inline virtual std::string `[`description`](#classargo_1_1handler_1_1group_1_1_plain_1af578ffc014b9ebd14157cde4364b986c)`() const` 

# namespace `argo::nargs` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`argo::nargs::FixedNumber`](#classargo_1_1nargs_1_1_fixed_number) | 
`class `[`argo::nargs::INargs`](#classargo_1_1nargs_1_1_i_nargs) | 
`class `[`argo::nargs::OneOrMore`](#classargo_1_1nargs_1_1_one_or_more) | 
`class `[`argo::nargs::Optional`](#classargo_1_1nargs_1_1_optional) | 
`class `[`argo::nargs::ZeroOrMore`](#classargo_1_1nargs_1_1_zero_or_more) | 

# class `argo::nargs::FixedNumber` 

```
class argo::nargs::FixedNumber
  : public argo::nargs::INargs
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`FixedNumber`](#classargo_1_1nargs_1_1_fixed_number_1a79e7011777ded76d1b0870bb2b68d2f6)`(const unsigned int max_count)` | 
`public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_fixed_number_1a6ffe09b7505e40572ba070fa2522fb17)`() const` | 
`public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_fixed_number_1ac28d0860770f57b7a1734de80ca97976)`()` | 
`public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_fixed_number_1a9d9594248b1030c63ed0d7ce8bbec48d)`()` | 
`public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_fixed_number_1a6937f6e99446d7cc26ed989e937e0777)`() const` | 

## Members

#### `public inline  explicit `[`FixedNumber`](#classargo_1_1nargs_1_1_fixed_number_1a79e7011777ded76d1b0870bb2b68d2f6)`(const unsigned int max_count)` 

#### `public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_fixed_number_1a6ffe09b7505e40572ba070fa2522fb17)`() const` 

#### `public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_fixed_number_1ac28d0860770f57b7a1734de80ca97976)`()` 

#### `public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_fixed_number_1a9d9594248b1030c63ed0d7ce8bbec48d)`()` 

#### `public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_fixed_number_1a6937f6e99446d7cc26ed989e937e0777)`() const` 

# class `argo::nargs::INargs` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~INargs`](#classargo_1_1nargs_1_1_i_nargs_1a36dc91ce890ac28789cbfab9c7cb2339)`() = default` | 
`public inline unsigned int `[`count`](#classargo_1_1nargs_1_1_i_nargs_1a4761bea49bd0e3a67fe5a403fdeffa41)`() const` | 
`public inline void `[`next`](#classargo_1_1nargs_1_1_i_nargs_1ae34e225b7d9cbd5771c735d90cb14425)`()` | 
`public Ptr `[`clone`](#classargo_1_1nargs_1_1_i_nargs_1a275186a36b8eb744bccec279b2a759c3)`() const` | 
`public bool `[`must_have_next`](#classargo_1_1nargs_1_1_i_nargs_1aa042af38069819fbde0a2610d90056c8)`()` | 
`public bool `[`may_have_next`](#classargo_1_1nargs_1_1_i_nargs_1ae97473a0c21d2edf4dd76d7958c29d14)`()` | 
`public std::string `[`description`](#classargo_1_1nargs_1_1_i_nargs_1a335e6d6ce88669aaaa7b90267982935b)`() const` | 
`protected unsigned int `[`count_`](#classargo_1_1nargs_1_1_i_nargs_1a4a9dbfcba967042b10bb0cc298c8842e) | 

## Members

#### `public virtual  `[`~INargs`](#classargo_1_1nargs_1_1_i_nargs_1a36dc91ce890ac28789cbfab9c7cb2339)`() = default` 

#### `public inline unsigned int `[`count`](#classargo_1_1nargs_1_1_i_nargs_1a4761bea49bd0e3a67fe5a403fdeffa41)`() const` 

#### `public inline void `[`next`](#classargo_1_1nargs_1_1_i_nargs_1ae34e225b7d9cbd5771c735d90cb14425)`()` 

#### `public Ptr `[`clone`](#classargo_1_1nargs_1_1_i_nargs_1a275186a36b8eb744bccec279b2a759c3)`() const` 

#### `public bool `[`must_have_next`](#classargo_1_1nargs_1_1_i_nargs_1aa042af38069819fbde0a2610d90056c8)`()` 

#### `public bool `[`may_have_next`](#classargo_1_1nargs_1_1_i_nargs_1ae97473a0c21d2edf4dd76d7958c29d14)`()` 

#### `public std::string `[`description`](#classargo_1_1nargs_1_1_i_nargs_1a335e6d6ce88669aaaa7b90267982935b)`() const` 

#### `protected unsigned int `[`count_`](#classargo_1_1nargs_1_1_i_nargs_1a4a9dbfcba967042b10bb0cc298c8842e) 

# class `argo::nargs::OneOrMore` 

```
class argo::nargs::OneOrMore
  : public argo::nargs::INargs
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_one_or_more_1a0a42ba480b713915e20ce3f6a5f2715f)`() const` | 
`public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_one_or_more_1ae88de1c652fd2ff456e9c972b8d84283)`()` | 
`public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_one_or_more_1aeeab664d5c788c180cc5577c9f98663f)`()` | 
`public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_one_or_more_1ab891d63beac00668a180caee33779e95)`() const` | 

## Members

#### `public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_one_or_more_1a0a42ba480b713915e20ce3f6a5f2715f)`() const` 

#### `public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_one_or_more_1ae88de1c652fd2ff456e9c972b8d84283)`()` 

#### `public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_one_or_more_1aeeab664d5c788c180cc5577c9f98663f)`()` 

#### `public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_one_or_more_1ab891d63beac00668a180caee33779e95)`() const` 

# class `argo::nargs::Optional` 

```
class argo::nargs::Optional
  : public argo::nargs::INargs
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_optional_1a53c0584d9a80e2c92af1e17dd8f6d510)`() const` | 
`public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_optional_1a8aae2d6640d6cafab85f88272cd06212)`()` | 
`public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_optional_1a0b163af1ffb2db77a5edacb32c75db45)`()` | 
`public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_optional_1aa828a9982a59b234c6ce434576594b0a)`() const` | 

## Members

#### `public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_optional_1a53c0584d9a80e2c92af1e17dd8f6d510)`() const` 

#### `public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_optional_1a8aae2d6640d6cafab85f88272cd06212)`()` 

#### `public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_optional_1a0b163af1ffb2db77a5edacb32c75db45)`()` 

#### `public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_optional_1aa828a9982a59b234c6ce434576594b0a)`() const` 

# class `argo::nargs::ZeroOrMore` 

```
class argo::nargs::ZeroOrMore
  : public argo::nargs::INargs
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_zero_or_more_1a9bc4da1e29b047f912c239918b65de80)`() const` | 
`public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_zero_or_more_1a2adb973c91b3623c086f2e7b7f2620ea)`()` | 
`public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_zero_or_more_1a233867e5bb4352836aade426557901fc)`()` | 
`public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_zero_or_more_1ae1b92517130a646feccf2233875fca45)`() const` | 

## Members

#### `public inline virtual Ptr `[`clone`](#classargo_1_1nargs_1_1_zero_or_more_1a9bc4da1e29b047f912c239918b65de80)`() const` 

#### `public inline virtual bool `[`must_have_next`](#classargo_1_1nargs_1_1_zero_or_more_1a2adb973c91b3623c086f2e7b7f2620ea)`()` 

#### `public inline virtual bool `[`may_have_next`](#classargo_1_1nargs_1_1_zero_or_more_1a233867e5bb4352836aade426557901fc)`()` 

#### `public inline virtual std::string `[`description`](#classargo_1_1nargs_1_1_zero_or_more_1ae1b92517130a646feccf2233875fca45)`() const` 

# namespace `argo::program` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`argo::program::Description`](#structargo_1_1program_1_1_description) | 
`struct `[`argo::program::Info`](#structargo_1_1program_1_1_info) | 
`struct `[`argo::program::Name`](#structargo_1_1program_1_1_name) | 
`struct `[`argo::program::Version`](#structargo_1_1program_1_1_version) | 

# struct `argo::program::Description` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::string `[`brief`](#structargo_1_1program_1_1_description_1afb301672d5e7dbae789838c2c66717e2) | 
`public std::string `[`extended`](#structargo_1_1program_1_1_description_1a8ccd6ae7042e6842e97bd12061fe6d69) | 
`public std::string `[`usage`](#structargo_1_1program_1_1_description_1accdbf27ff8394bd21e7672a80a938118) | 

## Members

#### `public std::string `[`brief`](#structargo_1_1program_1_1_description_1afb301672d5e7dbae789838c2c66717e2) 

#### `public std::string `[`extended`](#structargo_1_1program_1_1_description_1a8ccd6ae7042e6842e97bd12061fe6d69) 

#### `public std::string `[`usage`](#structargo_1_1program_1_1_description_1accdbf27ff8394bd21e7672a80a938118) 

# struct `argo::program::Info` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Name`](#structargo_1_1program_1_1_name)` `[`name`](#structargo_1_1program_1_1_info_1ab6d6c416a89b39b264718d4b46bb604a) | 
`public `[`Description`](#structargo_1_1program_1_1_description)` `[`description`](#structargo_1_1program_1_1_info_1ab6c0796829f97dcdf98d56dc2d763e3b) | 
`public `[`Version`](#structargo_1_1program_1_1_version)` `[`version`](#structargo_1_1program_1_1_info_1a7181900f09c97077320f5cfd73930b19) | 

## Members

#### `public `[`Name`](#structargo_1_1program_1_1_name)` `[`name`](#structargo_1_1program_1_1_info_1ab6d6c416a89b39b264718d4b46bb604a) 

#### `public `[`Description`](#structargo_1_1program_1_1_description)` `[`description`](#structargo_1_1program_1_1_info_1ab6c0796829f97dcdf98d56dc2d763e3b) 

#### `public `[`Version`](#structargo_1_1program_1_1_version)` `[`version`](#structargo_1_1program_1_1_info_1a7181900f09c97077320f5cfd73930b19) 

# struct `argo::program::Name` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::string `[`brief`](#structargo_1_1program_1_1_name_1a2520a6f8abf43bcacaa9aa633d5706bc) | 
`public std::string `[`extended`](#structargo_1_1program_1_1_name_1af7f96449ab7d2260dbac0b2a0b0a6f65) | 

## Members

#### `public std::string `[`brief`](#structargo_1_1program_1_1_name_1a2520a6f8abf43bcacaa9aa633d5706bc) 

#### `public std::string `[`extended`](#structargo_1_1program_1_1_name_1af7f96449ab7d2260dbac0b2a0b0a6f65) 

# struct `argo::program::Version` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned `[`major`](#structargo_1_1program_1_1_version_1abb0fad01a0291cc0c768d701f78d1472) | 
`public unsigned `[`minor`](#structargo_1_1program_1_1_version_1a96f0cf912e18fceae1f31e0529de8341) | 
`public unsigned `[`patch`](#structargo_1_1program_1_1_version_1aa5399d500cc085614a6e88fd6f914763) | 
`public std::string `[`githash`](#structargo_1_1program_1_1_version_1a9439349473f15d72da87eec179f6c226) | 

## Members

#### `public unsigned `[`major`](#structargo_1_1program_1_1_version_1abb0fad01a0291cc0c768d701f78d1472) 

#### `public unsigned `[`minor`](#structargo_1_1program_1_1_version_1a96f0cf912e18fceae1f31e0529de8341) 

#### `public unsigned `[`patch`](#structargo_1_1program_1_1_version_1aa5399d500cc085614a6e88fd6f914763) 

#### `public std::string `[`githash`](#structargo_1_1program_1_1_version_1a9439349473f15d72da87eec179f6c226) 

# namespace `argo::traits` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`argo::traits::conversion`](#structargo_1_1traits_1_1conversion) | 
`struct `[`argo::traits::conversion< bool >`](#structargo_1_1traits_1_1conversion_3_01bool_01_4) | 
`struct `[`argo::traits::conversion< double >`](#structargo_1_1traits_1_1conversion_3_01double_01_4) | 
`struct `[`argo::traits::conversion< float >`](#structargo_1_1traits_1_1conversion_3_01float_01_4) | 
`struct `[`argo::traits::conversion< std::string >`](#structargo_1_1traits_1_1conversion_3_01std_1_1string_01_4) | 
`struct `[`argo::traits::conversion< T, typename std::enable_if< std::is_enum< T >::value >::type >`](#structargo_1_1traits_1_1conversion_3_01_t_00_01typename_01std_1_1enable__if_3_01std_1_1is__enum_c403fd551c82290f26fc17b6bad08afe) | 
`struct `[`argo::traits::conversion< unsigned int >`](#structargo_1_1traits_1_1conversion_3_01unsigned_01int_01_4) | 
`struct `[`argo::traits::no_conversion`](#structargo_1_1traits_1_1no__conversion) | 

# struct `argo::traits::conversion` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< bool >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< double >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< float >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< std::string >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< T, typename std::enable_if< std::is_enum< T >::value >::type >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::conversion< unsigned int >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::traits::no_conversion` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::Text::Boolalpha` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::Text::Color::Code` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< unsigned int > `[`sequence`](#structargo_1_1details_1_1string_1_1_text_1_1_color_1_1_code_1abd7c7fd790a7ea1b5a92eefc9db8b66c) | 

## Members

#### `public std::vector< unsigned int > `[`sequence`](#structargo_1_1details_1_1string_1_1_text_1_1_color_1_1_code_1abd7c7fd790a7ea1b5a92eefc9db8b66c) 

# struct `argo::details::string::Text::Color` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::Text::Endline` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::Text::Indent` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `argo::details::string::Text::Outdent` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

Generated by [Moxygen](https://sourcey.com/moxygen)