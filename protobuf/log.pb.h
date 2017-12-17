// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#ifndef PROTOBUF_log_2eproto__INCLUDED
#define PROTOBUF_log_2eproto__INCLUDED

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_log_2eproto {
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
void InitDefaultsSendLogImpl();
void InitDefaultsSendLog();
inline void InitDefaults() {
  InitDefaultsSendLog();
}
}  // namespace protobuf_log_2eproto
namespace zxtest {
namespace log {
class SendLog;
class SendLogDefaultTypeInternal;
extern SendLogDefaultTypeInternal _SendLog_default_instance_;
}  // namespace log
}  // namespace zxtest
namespace google {
namespace protobuf {
template<> ::zxtest::log::SendLog* Arena::Create< ::zxtest::log::SendLog>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace zxtest {
namespace log {

enum Recode {
  SUCCESS = 0,
  ERROR = 1,
  Recode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Recode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Recode_IsValid(int value);
const Recode Recode_MIN = SUCCESS;
const Recode Recode_MAX = ERROR;
const int Recode_ARRAYSIZE = Recode_MAX + 1;

const ::google::protobuf::EnumDescriptor* Recode_descriptor();
inline const ::std::string& Recode_Name(Recode value) {
  return ::google::protobuf::internal::NameOfEnum(
    Recode_descriptor(), value);
}
inline bool Recode_Parse(
    const ::std::string& name, Recode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Recode>(
    Recode_descriptor(), name, value);
}
// ===================================================================

class SendLog : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zxtest.log.SendLog) */ {
 public:
  SendLog();
  virtual ~SendLog();

  SendLog(const SendLog& from);

  inline SendLog& operator=(const SendLog& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SendLog(SendLog&& from) noexcept
    : SendLog() {
    *this = ::std::move(from);
  }

  inline SendLog& operator=(SendLog&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SendLog& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SendLog* internal_default_instance() {
    return reinterpret_cast<const SendLog*>(
               &_SendLog_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(SendLog* other);
  friend void swap(SendLog& a, SendLog& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SendLog* New() const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<SendLog>(NULL);
  }

  SendLog* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<SendLog>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SendLog& from);
  void MergeFrom(const SendLog& from);
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
  void InternalSwap(SendLog* other);
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

  // string sname = 1;
  void clear_sname();
  static const int kSnameFieldNumber = 1;
  const ::std::string& sname() const;
  void set_sname(const ::std::string& value);
  #if LANG_CXX11
  void set_sname(::std::string&& value);
  #endif
  void set_sname(const char* value);
  void set_sname(const char* value, size_t size);
  ::std::string* mutable_sname();
  ::std::string* release_sname();
  void set_allocated_sname(::std::string* sname);

  // string Log = 2;
  void clear_log();
  static const int kLogFieldNumber = 2;
  const ::std::string& log() const;
  void set_log(const ::std::string& value);
  #if LANG_CXX11
  void set_log(::std::string&& value);
  #endif
  void set_log(const char* value);
  void set_log(const char* value, size_t size);
  ::std::string* mutable_log();
  ::std::string* release_log();
  void set_allocated_log(::std::string* log);

  // @@protoc_insertion_point(class_scope:zxtest.log.SendLog)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr sname_;
  ::google::protobuf::internal::ArenaStringPtr log_;
  mutable int _cached_size_;
  friend struct ::protobuf_log_2eproto::TableStruct;
  friend void ::protobuf_log_2eproto::InitDefaultsSendLogImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SendLog

// string sname = 1;
inline void SendLog::clear_sname() {
  sname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendLog::sname() const {
  // @@protoc_insertion_point(field_get:zxtest.log.SendLog.sname)
  return sname_.GetNoArena();
}
inline void SendLog::set_sname(const ::std::string& value) {
  
  sname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zxtest.log.SendLog.sname)
}
#if LANG_CXX11
inline void SendLog::set_sname(::std::string&& value) {
  
  sname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zxtest.log.SendLog.sname)
}
#endif
inline void SendLog::set_sname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  sname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zxtest.log.SendLog.sname)
}
inline void SendLog::set_sname(const char* value, size_t size) {
  
  sname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zxtest.log.SendLog.sname)
}
inline ::std::string* SendLog::mutable_sname() {
  
  // @@protoc_insertion_point(field_mutable:zxtest.log.SendLog.sname)
  return sname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendLog::release_sname() {
  // @@protoc_insertion_point(field_release:zxtest.log.SendLog.sname)
  
  return sname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendLog::set_allocated_sname(::std::string* sname) {
  if (sname != NULL) {
    
  } else {
    
  }
  sname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sname);
  // @@protoc_insertion_point(field_set_allocated:zxtest.log.SendLog.sname)
}

// string Log = 2;
inline void SendLog::clear_log() {
  log_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SendLog::log() const {
  // @@protoc_insertion_point(field_get:zxtest.log.SendLog.Log)
  return log_.GetNoArena();
}
inline void SendLog::set_log(const ::std::string& value) {
  
  log_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zxtest.log.SendLog.Log)
}
#if LANG_CXX11
inline void SendLog::set_log(::std::string&& value) {
  
  log_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zxtest.log.SendLog.Log)
}
#endif
inline void SendLog::set_log(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  log_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zxtest.log.SendLog.Log)
}
inline void SendLog::set_log(const char* value, size_t size) {
  
  log_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zxtest.log.SendLog.Log)
}
inline ::std::string* SendLog::mutable_log() {
  
  // @@protoc_insertion_point(field_mutable:zxtest.log.SendLog.Log)
  return log_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SendLog::release_log() {
  // @@protoc_insertion_point(field_release:zxtest.log.SendLog.Log)
  
  return log_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SendLog::set_allocated_log(::std::string* log) {
  if (log != NULL) {
    
  } else {
    
  }
  log_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), log);
  // @@protoc_insertion_point(field_set_allocated:zxtest.log.SendLog.Log)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace log
}  // namespace zxtest

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::zxtest::log::Recode> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::zxtest::log::Recode>() {
  return ::zxtest::log::Recode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_log_2eproto__INCLUDED