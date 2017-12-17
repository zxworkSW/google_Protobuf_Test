// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#ifndef PROTOBUF_user_2eproto__INCLUDED
#define PROTOBUF_user_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_user_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsUserInfoImpl();
void InitDefaultsUserInfo();
inline void InitDefaults() {
  InitDefaultsUserInfo();
}
}  // namespace protobuf_user_2eproto
namespace zxtest {
namespace user {
class UserInfo;
class UserInfoDefaultTypeInternal;
extern UserInfoDefaultTypeInternal _UserInfo_default_instance_;
}  // namespace user
}  // namespace zxtest
namespace google {
namespace protobuf {
template<> ::zxtest::user::UserInfo* Arena::Create< ::zxtest::user::UserInfo>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace zxtest {
namespace user {

// ===================================================================

class UserInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zxtest.user.UserInfo) */ {
 public:
  UserInfo();
  virtual ~UserInfo();

  UserInfo(const UserInfo& from);

  inline UserInfo& operator=(const UserInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  UserInfo(UserInfo&& from) noexcept
    : UserInfo() {
    *this = ::std::move(from);
  }

  inline UserInfo& operator=(UserInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserInfo* internal_default_instance() {
    return reinterpret_cast<const UserInfo*>(
               &_UserInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(UserInfo* other);
  friend void swap(UserInfo& a, UserInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UserInfo* New() const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<UserInfo>(NULL);
  }

  UserInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<UserInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const UserInfo& from);
  void MergeFrom(const UserInfo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(UserInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string username = 1;
  void clear_username();
  static const int kUsernameFieldNumber = 1;
  const ::std::string& username() const;
  void set_username(const ::std::string& value);
  #if LANG_CXX11
  void set_username(::std::string&& value);
  #endif
  void set_username(const char* value);
  void set_username(const char* value, size_t size);
  ::std::string* mutable_username();
  ::std::string* release_username();
  void set_allocated_username(::std::string* username);

  // uint32 index = 2;
  void clear_index();
  static const int kIndexFieldNumber = 2;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:zxtest.user.UserInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::uint32 index_;
  mutable int _cached_size_;
  friend struct ::protobuf_user_2eproto::TableStruct;
  friend void ::protobuf_user_2eproto::InitDefaultsUserInfoImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserInfo

// uint32 index = 2;
inline void UserInfo::clear_index() {
  index_ = 0u;
}
inline ::google::protobuf::uint32 UserInfo::index() const {
  // @@protoc_insertion_point(field_get:zxtest.user.UserInfo.index)
  return index_;
}
inline void UserInfo::set_index(::google::protobuf::uint32 value) {
  
  index_ = value;
  // @@protoc_insertion_point(field_set:zxtest.user.UserInfo.index)
}

// string username = 1;
inline void UserInfo::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserInfo::username() const {
  // @@protoc_insertion_point(field_get:zxtest.user.UserInfo.username)
  return username_.GetNoArena();
}
inline void UserInfo::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zxtest.user.UserInfo.username)
}
#if LANG_CXX11
inline void UserInfo::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zxtest.user.UserInfo.username)
}
#endif
inline void UserInfo::set_username(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zxtest.user.UserInfo.username)
}
inline void UserInfo::set_username(const char* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zxtest.user.UserInfo.username)
}
inline ::std::string* UserInfo::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:zxtest.user.UserInfo.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserInfo::release_username() {
  // @@protoc_insertion_point(field_release:zxtest.user.UserInfo.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_username(::std::string* username) {
  if (username != NULL) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:zxtest.user.UserInfo.username)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace user
}  // namespace zxtest

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_user_2eproto__INCLUDED