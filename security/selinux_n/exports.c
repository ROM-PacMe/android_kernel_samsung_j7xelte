/*
 * SELinux services exported to the rest of the kernel.
 *
 * Author: James Morris <jmorris@redhat.com>
 *
 * Copyright (C) 2005 Red Hat, Inc., James Morris <jmorris@redhat.com>
 * Copyright (C) 2006 Trusted Computer Solutions, Inc. <dgoeddel@trustedcs.com>
 * Copyright (C) 2006 IBM Corporation, Timothy R. Chavez <tinytim@us.ibm.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2,
 * as published by the Free Software Foundation.
 */
#include <linux/module.h>
#include <linux/selinux.h>

#include "security.h"
#include "avc.h"

bool selinux_is_enabled(void)
{
// [ SEC_SELINUX_PORTING_COMMON
#ifdef CONFIG_SECURITY_SELINUX_ALWAYS_ENFORCE
	return true;
#else
	return selinux_enabled;
#endif
// ] SEC_SELINUX_PORTING_COMMON
}
EXPORT_SYMBOL_GPL(selinux_is_enabled);

bool selinux_is_enforcing(void)
{
// [ SEC_SELINUX_PORTING_COMMON
#if defined(CONFIG_SECURITY_SELINUX_ALWAYS_ENFORCE)
	return true;
#elif defined(CONFIG_SECURITY_SELINUX_NEVER_ENFORCE)
	return false;
#else
	return selinux_enforcing;
#endif
// ] SEC_SELINUX_PORTING_COMMON
}
EXPORT_SYMBOL_GPL(selinux_is_enforcing);