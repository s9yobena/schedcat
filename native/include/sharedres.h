#ifndef SHAREDRES_H
#define SHAREDRES_H

#include "sharedres_types.h"

// spinlocks

BlockingBounds* task_fair_mutex_bounds(const ResourceSharingInfo& info,
				       unsigned int procs_per_cluster,
				       int dedicated_irq = NO_CPU);

BlockingBounds* task_fair_rw_bounds(const ResourceSharingInfo& info,
				    const ResourceSharingInfo& info_mtx,
				    unsigned int procs_per_cluster,
				    int dedicated_irq = NO_CPU);

BlockingBounds* phase_fair_rw_bounds(const ResourceSharingInfo& info,
				     unsigned int procs_per_cluster,
				     int dedicated_irq = NO_CPU);

// s-oblivious protocols

BlockingBounds* global_omlp_bounds(const ResourceSharingInfo& info,
				   unsigned int num_procs);
BlockingBounds* global_fmlp_bounds(const ResourceSharingInfo& info);

BlockingBounds* clustered_omlp_bounds(const ResourceSharingInfo& info,
				      unsigned int procs_per_cluster,
				      int dedicated_irq = NO_CPU);

BlockingBounds* clustered_rw_omlp_bounds(const ResourceSharingInfo& info,
					 unsigned int procs_per_cluster,
					 int dedicated_irq = NO_CPU);

BlockingBounds* clustered_kx_omlp_bounds(const ResourceSharingInfo& info,
					 const ReplicaInfo& replicaInfo,
					 unsigned int procs_per_cluster,
					 int dedicated_irq);

BlockingBounds* part_omlp_bounds(const ResourceSharingInfo& info);


// s-aware protocols

BlockingBounds* part_fmlp_bounds(const ResourceSharingInfo& info,
				 bool preemptive = true);

BlockingBounds* mpcp_bounds(const ResourceSharingInfo& info,
			    bool use_virtual_spinning);

BlockingBounds* dpcp_bounds(const ResourceSharingInfo& info,
			    const ResourceLocality& locality);

// Still missing:
// ==============

// clustered_omlp_kex_bounds
// clustered_omlp_rw_bounds
// spin_rw_wpref_bounds
// spin_rw_rpref_bounds



#endif
