
/*
 * Linux kernel ALIGN macro
 */

#include <stdio.h>

/* .config */
#define CONFIG_ARM_L1_CACHE_SHIFT	6

#define max(x, y) ({				\
	typeof(x) _max1 = (x);			\
	typeof(y) _max2 = (y);			\
	(void) (&_max1 == &_max2);		\
	_max1 > _max2 ? _max1 : _max2; })

/* arch/arm/include/asm/cache.h */
#define L1_CACHE_SHIFT		CONFIG_ARM_L1_CACHE_SHIFT
#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)

/* include/linux/cache.h */
#ifndef SMP_CACHE_BYTES
#define SMP_CACHE_BYTES L1_CACHE_BYTES
#endif

/* include/uapi/linux/kernel.h */
#define __ALIGN_KERNEL_MASK(x, mask)	(((x) + (mask)) & ~(mask))
#define __ALIGN_KERNEL(x, a)		__ALIGN_KERNEL_MASK(x, (typeof(x))(a) - 1)

/* include/linux/kernel.h */
#define ALIGN(x, a)		__ALIGN_KERNEL((x), (a))

/* include/linux/skbuff.h */
#define SKB_DATA_ALIGN(X)	ALIGN(X, SMP_CACHE_BYTES)

#ifndef NET_SKB_PAD
#define NET_SKB_PAD	max(32, L1_CACHE_BYTES)
#endif

#define SKB_RECYCLE_SIZE	2304
#define SKB_RECYCLE_MIN_SIZE	SKB_RECYCLE_SIZE
#define SKB_RECYCLE_MAX_SIZE	(3904 - NET_SKB_PAD)

int main(void)
{
	int min_skb_size;
	int max_skb_size;

	min_skb_size = SKB_DATA_ALIGN(SKB_RECYCLE_MIN_SIZE + NET_SKB_PAD);
	max_skb_size = SKB_DATA_ALIGN(SKB_RECYCLE_MAX_SIZE + NET_SKB_PAD);

	printf("skb_recycle_min_size: %d, skb_recycle_max_size: %d\n",
		min_skb_size, max_skb_size);

	return 0;
}
