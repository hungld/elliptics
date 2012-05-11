#ifndef __ELLIPTICS_SRW_BASE_HPP
#define __ELLIPTICS_SRW_BASE_HPP

struct sph {
	uint64_t		data_size;		/* size of text data in @data - located after even string */
	uint64_t		binary_size;		/* size of binary data in @data - located after text data */
	uint64_t		flags;
	int			event_size;		/* size of the event string - it is located first in @data */
	int			status;			/* processing status - negative errno code or zero on success */
	int			key;			/* meta-key - used to map header to particular worker, see pool::worker_process() */
	int			pad;
	char			data[0];
} __attribute__ ((packed));

struct srw_init_ctl {
	char			*binary;		/* path to srw_worker binary - it is used to spawn script workers */
	char			*log;			/* srw log path - initialized to the same config string as for 'log' by default */
	char			*pipe;			/* pipe base - elliptics will talk to workers via @pipe.c2w and @pipe.w2c */
	char			*init;			/* path to initialization object */
	char			*config;		/* path to config object */
	void			*priv;			/* opaque private data */
	int			pad;			/* srw worker type */
	int			num;			/* number of workers */
} __attribute__ ((packed));

#endif
