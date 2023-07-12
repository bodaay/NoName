// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bridgelink_pytorch.proto

#include "bridgelink_pytorch.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = ::PROTOBUF_NAMESPACE_ID::internal;
namespace bridgelink {
template <typename>
PROTOBUF_CONSTEXPR CudaAvailableRequest::CudaAvailableRequest(
    ::_pbi::ConstantInitialized) {}
struct CudaAvailableRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CudaAvailableRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CudaAvailableRequestDefaultTypeInternal() {}
  union {
    CudaAvailableRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CudaAvailableRequestDefaultTypeInternal _CudaAvailableRequest_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR CudaAvailableResponse::CudaAvailableResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.available_)*/ false

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct CudaAvailableResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CudaAvailableResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CudaAvailableResponseDefaultTypeInternal() {}
  union {
    CudaAvailableResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CudaAvailableResponseDefaultTypeInternal _CudaAvailableResponse_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR CudaDeviceCountRequest::CudaDeviceCountRequest(
    ::_pbi::ConstantInitialized) {}
struct CudaDeviceCountRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CudaDeviceCountRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CudaDeviceCountRequestDefaultTypeInternal() {}
  union {
    CudaDeviceCountRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CudaDeviceCountRequestDefaultTypeInternal _CudaDeviceCountRequest_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR CudaDeviceCountResponse::CudaDeviceCountResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.count_)*/ 0

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct CudaDeviceCountResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CudaDeviceCountResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CudaDeviceCountResponseDefaultTypeInternal() {}
  union {
    CudaDeviceCountResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CudaDeviceCountResponseDefaultTypeInternal _CudaDeviceCountResponse_default_instance_;
}  // namespace bridgelink
static ::_pb::Metadata file_level_metadata_bridgelink_5fpytorch_2eproto[4];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_bridgelink_5fpytorch_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_bridgelink_5fpytorch_2eproto = nullptr;
const ::uint32_t TableStruct_bridgelink_5fpytorch_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaAvailableRequest, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaAvailableResponse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaAvailableResponse, _impl_.available_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaDeviceCountRequest, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaDeviceCountResponse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::bridgelink::CudaDeviceCountResponse, _impl_.count_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::bridgelink::CudaAvailableRequest)},
        { 8, -1, -1, sizeof(::bridgelink::CudaAvailableResponse)},
        { 17, -1, -1, sizeof(::bridgelink::CudaDeviceCountRequest)},
        { 25, -1, -1, sizeof(::bridgelink::CudaDeviceCountResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::bridgelink::_CudaAvailableRequest_default_instance_._instance,
    &::bridgelink::_CudaAvailableResponse_default_instance_._instance,
    &::bridgelink::_CudaDeviceCountRequest_default_instance_._instance,
    &::bridgelink::_CudaDeviceCountResponse_default_instance_._instance,
};
const char descriptor_table_protodef_bridgelink_5fpytorch_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\030bridgelink_pytorch.proto\022\nbridgelink\"\026"
    "\n\024CudaAvailableRequest\"*\n\025CudaAvailableR"
    "esponse\022\021\n\tavailable\030\001 \001(\010\"\030\n\026CudaDevice"
    "CountRequest\"(\n\027CudaDeviceCountResponse\022"
    "\r\n\005count\030\001 \001(\0052\313\001\n\016PyTorchService\022X\n\017IsC"
    "udaAvailable\022 .bridgelink.CudaAvailableR"
    "equest\032!.bridgelink.CudaAvailableRespons"
    "e\"\000\022_\n\022GetCudaDeviceCount\022\".bridgelink.C"
    "udaDeviceCountRequest\032#.bridgelink.CudaD"
    "eviceCountResponse\"\000B\035Z\033BridgeLinkClient"
    "/bridgelinkb\006proto3"
};
static ::absl::once_flag descriptor_table_bridgelink_5fpytorch_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_bridgelink_5fpytorch_2eproto = {
    false,
    false,
    419,
    descriptor_table_protodef_bridgelink_5fpytorch_2eproto,
    "bridgelink_pytorch.proto",
    &descriptor_table_bridgelink_5fpytorch_2eproto_once,
    nullptr,
    0,
    4,
    schemas,
    file_default_instances,
    TableStruct_bridgelink_5fpytorch_2eproto::offsets,
    file_level_metadata_bridgelink_5fpytorch_2eproto,
    file_level_enum_descriptors_bridgelink_5fpytorch_2eproto,
    file_level_service_descriptors_bridgelink_5fpytorch_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_bridgelink_5fpytorch_2eproto_getter() {
  return &descriptor_table_bridgelink_5fpytorch_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_bridgelink_5fpytorch_2eproto(&descriptor_table_bridgelink_5fpytorch_2eproto);
namespace bridgelink {
// ===================================================================

class CudaAvailableRequest::_Internal {
 public:
};

CudaAvailableRequest::CudaAvailableRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena) {
  // @@protoc_insertion_point(arena_constructor:bridgelink.CudaAvailableRequest)
}
CudaAvailableRequest::CudaAvailableRequest(const CudaAvailableRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  CudaAvailableRequest* const _this = this; (void)_this;
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:bridgelink.CudaAvailableRequest)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CudaAvailableRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CudaAvailableRequest::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata CudaAvailableRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_bridgelink_5fpytorch_2eproto_getter, &descriptor_table_bridgelink_5fpytorch_2eproto_once,
      file_level_metadata_bridgelink_5fpytorch_2eproto[0]);
}
// ===================================================================

class CudaAvailableResponse::_Internal {
 public:
};

CudaAvailableResponse::CudaAvailableResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:bridgelink.CudaAvailableResponse)
}
CudaAvailableResponse::CudaAvailableResponse(const CudaAvailableResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(), _impl_(from._impl_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
      from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:bridgelink.CudaAvailableResponse)
}

inline void CudaAvailableResponse::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.available_) { false }

    , /*decltype(_impl_._cached_size_)*/{}
  };
}

CudaAvailableResponse::~CudaAvailableResponse() {
  // @@protoc_insertion_point(destructor:bridgelink.CudaAvailableResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CudaAvailableResponse::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
}

void CudaAvailableResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CudaAvailableResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:bridgelink.CudaAvailableResponse)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.available_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CudaAvailableResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool available = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 8)) {
          _impl_.available_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* CudaAvailableResponse::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bridgelink.CudaAvailableResponse)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool available = 1;
  if (this->_internal_available() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        1, this->_internal_available(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bridgelink.CudaAvailableResponse)
  return target;
}

::size_t CudaAvailableResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bridgelink.CudaAvailableResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool available = 1;
  if (this->_internal_available() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CudaAvailableResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CudaAvailableResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CudaAvailableResponse::GetClassData() const { return &_class_data_; }


void CudaAvailableResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CudaAvailableResponse*>(&to_msg);
  auto& from = static_cast<const CudaAvailableResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:bridgelink.CudaAvailableResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_available() != 0) {
    _this->_internal_set_available(from._internal_available());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CudaAvailableResponse::CopyFrom(const CudaAvailableResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bridgelink.CudaAvailableResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CudaAvailableResponse::IsInitialized() const {
  return true;
}

void CudaAvailableResponse::InternalSwap(CudaAvailableResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);

  swap(_impl_.available_, other->_impl_.available_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CudaAvailableResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_bridgelink_5fpytorch_2eproto_getter, &descriptor_table_bridgelink_5fpytorch_2eproto_once,
      file_level_metadata_bridgelink_5fpytorch_2eproto[1]);
}
// ===================================================================

class CudaDeviceCountRequest::_Internal {
 public:
};

CudaDeviceCountRequest::CudaDeviceCountRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena) {
  // @@protoc_insertion_point(arena_constructor:bridgelink.CudaDeviceCountRequest)
}
CudaDeviceCountRequest::CudaDeviceCountRequest(const CudaDeviceCountRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  CudaDeviceCountRequest* const _this = this; (void)_this;
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:bridgelink.CudaDeviceCountRequest)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CudaDeviceCountRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CudaDeviceCountRequest::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata CudaDeviceCountRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_bridgelink_5fpytorch_2eproto_getter, &descriptor_table_bridgelink_5fpytorch_2eproto_once,
      file_level_metadata_bridgelink_5fpytorch_2eproto[2]);
}
// ===================================================================

class CudaDeviceCountResponse::_Internal {
 public:
};

CudaDeviceCountResponse::CudaDeviceCountResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:bridgelink.CudaDeviceCountResponse)
}
CudaDeviceCountResponse::CudaDeviceCountResponse(const CudaDeviceCountResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(), _impl_(from._impl_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
      from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:bridgelink.CudaDeviceCountResponse)
}

inline void CudaDeviceCountResponse::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.count_) { 0 }

    , /*decltype(_impl_._cached_size_)*/{}
  };
}

CudaDeviceCountResponse::~CudaDeviceCountResponse() {
  // @@protoc_insertion_point(destructor:bridgelink.CudaDeviceCountResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CudaDeviceCountResponse::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
}

void CudaDeviceCountResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CudaDeviceCountResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:bridgelink.CudaDeviceCountResponse)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.count_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CudaDeviceCountResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 count = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 8)) {
          _impl_.count_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* CudaDeviceCountResponse::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bridgelink.CudaDeviceCountResponse)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 count = 1;
  if (this->_internal_count() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(
        1, this->_internal_count(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bridgelink.CudaDeviceCountResponse)
  return target;
}

::size_t CudaDeviceCountResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bridgelink.CudaDeviceCountResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 count = 1;
  if (this->_internal_count() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_count());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CudaDeviceCountResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CudaDeviceCountResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CudaDeviceCountResponse::GetClassData() const { return &_class_data_; }


void CudaDeviceCountResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CudaDeviceCountResponse*>(&to_msg);
  auto& from = static_cast<const CudaDeviceCountResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:bridgelink.CudaDeviceCountResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_count() != 0) {
    _this->_internal_set_count(from._internal_count());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CudaDeviceCountResponse::CopyFrom(const CudaDeviceCountResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bridgelink.CudaDeviceCountResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CudaDeviceCountResponse::IsInitialized() const {
  return true;
}

void CudaDeviceCountResponse::InternalSwap(CudaDeviceCountResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);

  swap(_impl_.count_, other->_impl_.count_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CudaDeviceCountResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_bridgelink_5fpytorch_2eproto_getter, &descriptor_table_bridgelink_5fpytorch_2eproto_once,
      file_level_metadata_bridgelink_5fpytorch_2eproto[3]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace bridgelink
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bridgelink::CudaAvailableRequest*
Arena::CreateMaybeMessage< ::bridgelink::CudaAvailableRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::bridgelink::CudaAvailableRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::bridgelink::CudaAvailableResponse*
Arena::CreateMaybeMessage< ::bridgelink::CudaAvailableResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::bridgelink::CudaAvailableResponse >(arena);
}
template<> PROTOBUF_NOINLINE ::bridgelink::CudaDeviceCountRequest*
Arena::CreateMaybeMessage< ::bridgelink::CudaDeviceCountRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::bridgelink::CudaDeviceCountRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::bridgelink::CudaDeviceCountResponse*
Arena::CreateMaybeMessage< ::bridgelink::CudaDeviceCountResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::bridgelink::CudaDeviceCountResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"