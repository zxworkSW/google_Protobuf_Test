// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#include "user.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace zxtest {
namespace user {
class UserInfoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<UserInfo>
      _instance;
} _UserInfo_default_instance_;
}  // namespace user
}  // namespace zxtest
namespace protobuf_user_2eproto {
void InitDefaultsUserInfoImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::zxtest::user::_UserInfo_default_instance_;
    new (ptr) ::zxtest::user::UserInfo();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::zxtest::user::UserInfo::InitAsDefaultInstance();
}

void InitDefaultsUserInfo() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsUserInfoImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zxtest::user::UserInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zxtest::user::UserInfo, index_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zxtest::user::UserInfo, username_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::zxtest::user::UserInfo)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::zxtest::user::_UserInfo_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "user.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\nuser.proto\022\013zxtest.user\"+\n\010UserInfo\022\r\n"
      "\005index\030\002 \001(\r\022\020\n\010username\030\001 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 78);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "user.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_user_2eproto
namespace zxtest {
namespace user {

// ===================================================================

void UserInfo::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int UserInfo::kIndexFieldNumber;
const int UserInfo::kUsernameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

UserInfo::UserInfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_user_2eproto::InitDefaultsUserInfo();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:zxtest.user.UserInfo)
}
UserInfo::UserInfo(const UserInfo& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  username_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.username().size() > 0) {
    username_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.username_);
  }
  index_ = from.index_;
  // @@protoc_insertion_point(copy_constructor:zxtest.user.UserInfo)
}

void UserInfo::SharedCtor() {
  username_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  index_ = 0u;
  _cached_size_ = 0;
}

UserInfo::~UserInfo() {
  // @@protoc_insertion_point(destructor:zxtest.user.UserInfo)
  SharedDtor();
}

void UserInfo::SharedDtor() {
  username_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void UserInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UserInfo::descriptor() {
  ::protobuf_user_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_user_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const UserInfo& UserInfo::default_instance() {
  ::protobuf_user_2eproto::InitDefaultsUserInfo();
  return *internal_default_instance();
}


void UserInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:zxtest.user.UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  index_ = 0u;
  _internal_metadata_.Clear();
}

bool UserInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:zxtest.user.UserInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string username = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_username()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->username().data(), static_cast<int>(this->username().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "zxtest.user.UserInfo.username"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 index = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &index_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:zxtest.user.UserInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:zxtest.user.UserInfo)
  return false;
#undef DO_
}

void UserInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:zxtest.user.UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string username = 1;
  if (this->username().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->username().data(), static_cast<int>(this->username().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "zxtest.user.UserInfo.username");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->username(), output);
  }

  // uint32 index = 2;
  if (this->index() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->index(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:zxtest.user.UserInfo)
}

::google::protobuf::uint8* UserInfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:zxtest.user.UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string username = 1;
  if (this->username().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->username().data(), static_cast<int>(this->username().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "zxtest.user.UserInfo.username");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->username(), target);
  }

  // uint32 index = 2;
  if (this->index() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->index(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:zxtest.user.UserInfo)
  return target;
}

size_t UserInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:zxtest.user.UserInfo)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string username = 1;
  if (this->username().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->username());
  }

  // uint32 index = 2;
  if (this->index() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->index());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void UserInfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:zxtest.user.UserInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const UserInfo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const UserInfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:zxtest.user.UserInfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:zxtest.user.UserInfo)
    MergeFrom(*source);
  }
}

void UserInfo::MergeFrom(const UserInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:zxtest.user.UserInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.username().size() > 0) {

    username_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.username_);
  }
  if (from.index() != 0) {
    set_index(from.index());
  }
}

void UserInfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:zxtest.user.UserInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserInfo::CopyFrom(const UserInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:zxtest.user.UserInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserInfo::IsInitialized() const {
  return true;
}

void UserInfo::Swap(UserInfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UserInfo::InternalSwap(UserInfo* other) {
  using std::swap;
  username_.Swap(&other->username_);
  swap(index_, other->index_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata UserInfo::GetMetadata() const {
  protobuf_user_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_user_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace user
}  // namespace zxtest
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::zxtest::user::UserInfo* Arena::Create< ::zxtest::user::UserInfo >(Arena* arena) {
  return Arena::CreateInternal< ::zxtest::user::UserInfo >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
