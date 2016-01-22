#ifndef __ACPI_NUMA_H
#define __ACPI_NUMA_H

#ifdef CONFIG_ACPI_NUMA
#include <linux/kernel.h>

/* Proximity bitmap length */
#if MAX_NUMNODES > 256
#define MAX_PXM_DOMAINS MAX_NUMNODES
#else
#define MAX_PXM_DOMAINS (256)	/* Old pxm spec is defined 8 bit */
#endif

extern int pxm_to_node(int);
extern int node_to_pxm(int);
extern int acpi_map_pxm_to_node(int);
extern unsigned char acpi_srat_revision;
extern int acpi_numa __initdata;

static inline void bad_srat(void)
{
	pr_err("SRAT: SRAT not used.\n");
	acpi_numa = -1;
}

static  inline int srat_disabled(void)
{
	return acpi_numa < 0;
}

#endif				/* CONFIG_ACPI_NUMA */
#endif				/* __ACP_NUMA_H */
