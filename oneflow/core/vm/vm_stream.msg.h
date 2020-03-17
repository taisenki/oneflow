#ifndef ONEFLOW_CORE_VM_VM_STREAM_H_
#define ONEFLOW_CORE_VM_VM_STREAM_H_

#include "oneflow/core/vm/vm_stream_desc.msg.h"
#include "oneflow/core/vm/vm_instruction.msg.h"
#include "oneflow/core/device/device_context.h"

namespace oneflow {
namespace vm {

class VmThread;

// clang-format off
OBJECT_MSG_BEGIN(VmStream);
  // methods
  PUBLIC void __Init__(VmThread* vm_thread, const VmStreamId& vm_stream_id);
  PUBLIC ObjectMsgPtr<VmInstrChain> NewVmInstrChain(VmInstructionMsg* vm_instr_msg);
  PUBLIC void DeleteVmInstrChain(ObjectMsgPtr<VmInstrChain>&&);
  PUBLIC int64_t parallel_id() const { return vm_stream_id().parallel_id(); }
  PUBLIC int64_t machine_id() const;

  // fields
  OBJECT_MSG_DEFINE_PTR(VmThread, vm_thread); 
  OBJECT_MSG_DEFINE_STRUCT(std::unique_ptr<DeviceCtx>, device_ctx);
  
  // links
  OBJECT_MSG_DEFINE_LIST_LINK(active_vm_stream_link);
  OBJECT_MSG_DEFINE_LIST_LINK(vm_thread_vm_stream_link);
  OBJECT_MSG_DEFINE_MAP_FLAT_MSG_KEY(VmStreamId, vm_stream_id);
  OBJECT_MSG_DEFINE_LIST_HEAD(VmInstrChain, vm_instr_chain_link, running_chain_list);
  OBJECT_MSG_DEFINE_LIST_HEAD(VmInstrChain, vm_instr_chain_link, free_chain_list);
  OBJECT_MSG_DEFINE_LIST_HEAD(CallbackMsg, callback_link, callback_list);
OBJECT_MSG_END(VmStream);
// clang-format on

}  // namespace vm
}  // namespace oneflow

#endif  // ONEFLOW_CORE_VM_VM_STREAM_H_
