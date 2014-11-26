#undef TRACE_SYSTEM
#define TRACE_SYSTEM addons

#if !defined(LTTNG_ADDONS_H_) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_ADDONS_H_

#include <linux/tracepoint.h>

LTTNG_TRACEPOINT_EVENT_CLASS(vmsync_template,
	TP_PROTO(unsigned int cnt, unsigned long vm_uid),
	TP_ARGS(cnt, vm_uid),
	TP_STRUCT__entry(
		__field(unsigned int, cnt)
		__field(unsigned long, vm_uid)
	),
	TP_fast_assign(
		tp_assign(cnt, cnt)
		tp_assign(vm_uid, vm_uid)
	),
	TP_printk("%u %lu", __entry->cnt, __entry->vm_uid)
)

LTTNG_TRACEPOINT_EVENT_INSTANCE(vmsync_template, vmsync_gh_guest,
	TP_PROTO(unsigned int cnt, unsigned long vm_uid),
	TP_ARGS(cnt, vm_uid))

LTTNG_TRACEPOINT_EVENT_INSTANCE(vmsync_template, vmsync_gh_host,
	TP_PROTO(unsigned int cnt, unsigned long vm_uid),
	TP_ARGS(cnt, vm_uid))

LTTNG_TRACEPOINT_EVENT_INSTANCE(vmsync_template, vmsync_hg_guest,
	TP_PROTO(unsigned int cnt, unsigned long vm_uid),
	TP_ARGS(cnt, vm_uid))

LTTNG_TRACEPOINT_EVENT_INSTANCE(vmsync_template, vmsync_hg_host,
	TP_PROTO(unsigned int cnt, unsigned long vm_uid),
	TP_ARGS(cnt, vm_uid))

#endif /* LTTNG_ADDONS_H_ */

/* This part must be outside protection */
#include "../../../probes/define_trace.h"
