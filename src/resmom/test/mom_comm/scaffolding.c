#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h> /* sockaddr_in */
#include <errno.h>

#include "mom_server.h" /* mom_server */
#include "resmon.h" /* PBS_MAXSERVER */
#include "attribute.h" /* attribute_def, pbs_attribute */
#include "net_connect.h" /* connection, PBS_NET_MAX_CONNECTIONS */
#include "log.h" /* LOG_BUF_SIZE */
#include "list_link.h" /* tlist_head */
#include "resource.h" /* resource_def */
#include "u_tree.h" /* AvlTree */
#include "resizable_array.h" /* resizable_array */
#include "pbs_job.h" /* job */
#include "mom_func.h" /* radix_buf */
#include "dis.h"

char *path_jobs; /* mom_main.c */
int multi_mom = 1; /* mom_main.c */
int svr_resc_size = 0; /* resc_def_all.c */
u_long localaddr = 0; /* mom_main.c */
time_t time_now = 0; /* mom_main.c */
mom_server mom_servers[PBS_MAXSERVER]; /* mom_server.c */
attribute_def job_attr_def[10]; /* src/server/job_attr_def.c */
int exiting_tasks = 0; /* mom_main.c */
const char *dis_emsg[10]; /* dis.h */
char *path_prologuserp; /* mom_main.c */
struct connection svr_conn[PBS_NET_MAX_CONNECTIONS]; /* net_server.c */
tlist_head svr_newjobs; /* mom_main.c */
resource_def *svr_resc_def; /* resc_def_all.c */
int port_care = TRUE; /* mom_main.c */
unsigned int pbs_rm_port = 0; /* mom_main.c */
AvlTree okclients; /* mom_main.c */
tlist_head mom_polljobs; /* mom_main.c */
char *path_prologp; /* mom_main.c */
tlist_head svr_alljobs; /* mom_main.c */
int LOGLEVEL = 7; /* force logging code to be exercised as tests run */ /* mom_main.c/pbsd_main.c */
int maxupdatesbeforesending = 0;
int    ServerStatUpdateInterval = DEFAULT_SERVER_STAT_UPDATES;
time_t          LastServerUpdateTime = 0;  /* NOTE: all servers updated together */

/*
 *  * inserts an item, resizing the array if necessary
 *   *
 *    * @return the index in the array or -1 on failure
 *     */
int insert_thing(resizable_array *ra, void *thing) 
  {
  return -1;
  }

#undef disrus
unsigned short disrus(int stream, int *retval)
  {
  fprintf(stderr, "The call to disrus needs to be mocked!!\n");
  exit(1);
  }

int job_save(job *pjob, int updatetype, int mom_port)
  {
  fprintf(stderr, "The call to job_save needs to be mocked!!\n");
  exit(1);
  }

void mom_job_purge(job *pjob)
  {
  fprintf(stderr, "The call to job_purge needs to be mocked!!\n");
  exit(1);
  }

int decode_DIS_svrattrl(struct tcp_chan *chan, tlist_head *phead)
  {
  fprintf(stderr, "The call to decode_DIS_svrattrl needs to be mocked!!\n");
  exit(1);
  }

ssize_t read_nonblocking_socket(int fd, void *buf, ssize_t count)
  {
  fprintf(stderr, "The call to read_nonblocking_socket needs to be mocked!!\n");
  exit(1);
  }

char * netaddr(struct sockaddr_in *ap)
  {
  fprintf(stderr, "The call to netaddr needs to be mocked!!\n");
  exit(1);
  }

int TMakeTmpDir(job *pjob, char *tmpdir)
  {
  fprintf(stderr, "The call to TMakeTmpDir needs to be mocked!!\n");
  exit(1);
  }

unsigned long gettime(resource *pres)
  {
  fprintf(stderr, "The call to gettime needs to be mocked!!\n");
  exit(1);
  }

void exec_bail(job *pjob, int code)
  {
  fprintf(stderr, "The call to exec_bail needs to be mocked!!\n");
  exit(1);
  }

int AVL_list(AvlTree tree, char **Buf, long *current_len, long *max_len)
  {
  fprintf(stderr, "The call to AVL_list needs to be mocked!!\n");
  exit(1);
  }

int exec_job_on_ms(job *pjob)
  {
  fprintf(stderr, "The call to exec_job_on_ms needs to be mocked!!\n");
  exit(1);
  }

struct passwd *check_pwd(job *pjob)
  {
  fprintf(stderr, "The call to check_pwd needs to be mocked!!\n");
  exit(1);
  }

int mom_do_poll(job *pjob)
  {
  fprintf(stderr, "The call to mom_do_poll needs to be mocked!!\n");
  exit(1);
  }

void delete_link(struct list_link *old)
  {
  fprintf(stderr, "The call to delete_link needs to be mocked!!\n");
  exit(1);
  }

void clear_dynamic_string(dynamic_string *ds)
  {
  fprintf(stderr, "The call to clear_dynamic_string needs to be mocked!!\n");
  exit(1);
  }

int add_hash(hash_table_t *ht, int value, void *key)
  {
  fprintf(stderr, "The call to add_hash needs to be mocked!!\n");
  exit(1);
  }

char *get_job_envvar(job *pjob, const char *variable)
  {
  fprintf(stderr, "The call to get_job_envvar needs to be mocked!!\n");
  exit(1);
  }

/*
 *  * initializes a dynamic string and returns it, or NULL if there is no memory
 *   *
 *    * @param initial_size - the initial size of the string, use default if -1
 *     * @param str - the initial string to place in the dynamic string if not NULL
 *      * @return - the dynamic string object or NULL if no memory
 *       */
dynamic_string *get_dynamic_string(

  int         initial_size, /* I (-1 means default) */
  const char *str)          /* I (optional) */

  {
  dynamic_string *ds = (dynamic_string *)calloc(1, sizeof(dynamic_string));

  if (ds == NULL)
    return(ds);

  if (initial_size > 0)
    ds->size = initial_size;
  else
    ds->size = DS_INITIAL_SIZE;

  ds->str = (char *)calloc(1, ds->size);

  if (ds->str == NULL)
    {
    free(ds);
    return(NULL);
    }

  /* initialize empty str */
  ds->used = 0;

  /* add the string if it exists */
  if (str != NULL)
    {
    if (append_dynamic_string(ds,str) != PBSE_NONE)
      {
      free_dynamic_string(ds);
      return(NULL);
      }
    }

  return(ds);
  } /* END get_dynamic_string() */


size_t need_to_grow(

  dynamic_string *ds,
  const char     *to_check)

  {
  size_t to_add = strlen(to_check) + 1;
  size_t to_grow = 0;

  if (ds->size < ds->used + to_add)
    {
    to_grow = to_add + ds->size;

    if (to_grow < (ds->size * 4))
      to_grow = ds->size * 4;
    }

  return(to_grow);
  } /* END need_to_grow() */




int resize_if_needed(

  dynamic_string *ds,
  const char     *to_check)

  {
  size_t  new_size = need_to_grow(ds, to_check);
  size_t  difference;
  char   *tmp;

  if (new_size > 0)
    {
    /* need to resize */
    difference = new_size - ds->size;

    if ((tmp = (char *)realloc(ds->str, new_size)) == NULL)
      return(ENOMEM);

    ds->str = tmp;
    /* zero out the new space as well */
    memset(ds->str + ds->size, 0, difference);
    ds->size = new_size;
    }

  return(PBSE_NONE);
  } /* END resize_if_needed() */


int append_dynamic_string(
    
  dynamic_string *ds,        /* M */
  const char     *to_append) /* I */

  {
  int len = strlen(to_append);
  int add_one = FALSE;
  int offset = ds->used;

  if (ds->used == 0)
    add_one = TRUE;
  else
    offset -= 1;

  resize_if_needed(ds, to_append);
  strcat(ds->str + offset, to_append);
    
  ds->used += len;

  if (add_one == TRUE)
    ds->used += 1;

  return(PBSE_NONE);
  } /* END append_dynamic_string() */

int open_tcp_stream_to_sisters(job *pjob, int com, tm_event_t parent_event, int mom_radix, hnodent *hosts, struct radix_buf **sister_list, tlist_head *phead, int flag)
  {
  fprintf(stderr, "The call to open_tcp_stream_to_sisters needs to be mocked!!\n");
  exit(1);
  }

int open_demux(u_long addr, int port)
  {
  fprintf(stderr, "The call to open_demux needs to be mocked!!\n");
  exit(1);
  }

int mom_get_sample()
  {
  fprintf(stderr, "The call to mom_get_sample needs to be mocked!!\n");
  exit(1);
  }

int run_pelog(int which, char *specpelog, job *pjog, int pe_io_type)
  {
  fprintf(stderr, "The call to run_pelog needs to be mocked!!\n");
  exit(1);
  }

#undef disrul
unsigned long disrul(struct tcp_chan * chan, int *retval)
  {
  fprintf(stderr, "The call to disrul needs to be mocked!!\n");
  exit(1);
  }

const char * getuname(void )
  {
  fprintf(stderr, "The call to getuname needs to be mocked!!\n");
  exit(1);
  }

size_t write_nonblocking_socket(int fd, const void *buf, ssize_t count)
  {
  fprintf(stderr, "The call to write_nonblocking_socket needs to be mocked!!\n");
  exit(1);
  }

struct tcp_chan *DIS_tcp_setup(int fd)
  {
  fprintf(stderr, "The call to DIS_tcp_setup needs to be mocked!!\n");
  exit(1);
  }

int find_attr(struct attribute_def *attr_def, const char *name, int limit)
  {
  fprintf(stderr, "The call to find_attr needs to be mocked!!\n");
  exit(1);
  }

#undef disrui
unsigned disrui(struct tcp_chan *chan, int *retval)
  {
  fprintf(stderr, "The call to disrui needs to be mocked!!\n");
  exit(1);
  }

int AVL_is_in_tree_no_port_compare(u_long key, uint16_t port, AvlTree tree)
  {
  fprintf(stderr, "The call to AVL_is_in_tree_no_port_compare needs to be mocked!!\n");
  exit(1);
  }

int kill_task(struct task *task, int sig, int pg)
  {
  fprintf(stderr, "The call to kill_task needs to be mocked!!\n");
  exit(1);
  }

int get_value_hash(hash_table_t *ht, void *key)
  {
  return -1;
  }

int DIS_tcp_wflush(struct tcp_chan * chan)
  {
  fprintf(stderr, "The call to DIS_tcp_wflush needs to be mocked!!\n");
  exit(1);
  }

int diswcs(struct tcp_chan * chan, const char *value, size_t nchars)
  {
  fprintf(stderr, "The call to diswcs needs to be mocked!!\n");
  exit(1);
  }

unsigned long getsize(resource *pres)
  {
  fprintf(stderr, "The call to getsize needs to be mocked!!\n");
  exit(1);
  }

void *get_next(list_link pl, char *file, int line)
  {
  fprintf(stderr, "The call to get_next needs to be mocked!!\n");
  exit(1);
  }

int add_host_to_sister_list(char *hostname, unsigned short port, struct radix_buf *rb)
  {
  fprintf(stderr, "The call to add_host_to_sister_list needs to be mocked!!\n");
  exit(1);
  }

char *disrcs(struct tcp_chan * chan, size_t *nchars, int *retval)
  {
  fprintf(stderr, "The call to disrcs needs to be mocked!!\n");
  exit(1);
  }

int start_process(task *tsk, char **argv, char **envp)
  {
  fprintf(stderr, "The call to start_process needs to be mocked!!\n");
  exit(1);
  }

#undef diswui
int diswui(struct tcp_chan * chan, unsigned value)
  {
  fprintf(stderr, "The call to diswui needs to be mocked!!\n");
  exit(1);
  }

void free_sisterlist(struct radix_buf **list, int radix)
  {
  fprintf(stderr, "The call to free_sisterlist needs to be mocked!!\n");
  exit(1);
  }

int write_tcp_reply(struct tcp_chan *chan, int protocol, int version, int command, int exit_code)
  {
  fprintf(stderr, "The call to write_tcp_reply needs to be mocked!!\n");
  exit(1);
  }

int mom_set_use(job *pjob)
  {
  fprintf(stderr, "The call to mom_set_use needs to be mocked!!\n");
  exit(1);
  }

void free_attrlist(tlist_head *pattrlisthead)
  {
  fprintf(stderr, "The call to free_attrlist needs to be mocked!!\n");
  exit(1);
  }

void attrl_fixlink(tlist_head *phead)
  {
  fprintf(stderr, "The call to attrl_fixlink needs to be mocked!!\n");
  exit(1);
  }

resource_def *find_resc_def(resource_def *rscdf, const char *name, int limit)
  {
  fprintf(stderr, "The call to find_resc_def needs to be mocked!!\n");
  exit(1);
  }

struct radix_buf **allocate_sister_list(int radix)
  {
  fprintf(stderr, "The call to allocate_sister_list needs to be mocked!!\n");
  exit(1);
  }

int disrst_count = 0;
char *disrst(struct tcp_chan * chan, int *retval)
  {
  if (--disrst_count > 0)
    {
    retval = DIS_SUCCESS;
    return strdup("hi");
    }
  *retval = DIS_EOF;
  return NULL;
  }

int tcp_connect_sockaddr(struct sockaddr *sa, size_t sa_size)
  {
  fprintf(stderr, "The call to tcp_connect_sockaddr needs to be mocked!!\n");
  exit(1);
  }

void append_link(tlist_head *head, list_link *new_link, void *pobj)
  {
  fprintf(stderr, "The call to append_link needs to be mocked!!\n");
  exit(1);
  }

void sister_job_nodes(job *pjob, char *radix_hosts, char *radix_ports )
  {
  fprintf(stderr, "The call to sister_job_nodes needs to be mocked!!\n");
  exit(1);
  }

int TTmpDirName(job *pjob, char *tmpdir, int tmdir_size)
  {
  fprintf(stderr, "The call to TTmpDirName needs to be mocked!!\n");
  exit(1);
  }

void job_nodes(job *pjob)
  {
  fprintf(stderr, "The call to job_nodes needs to be mocked!!\n");
  exit(1);
  }

void close_conn(int sd, int has_mutex)
  {
  fprintf(stderr, "The call to close_conn needs to be mocked!!\n");
  exit(1);
  }

int copy_to_end_of_dynamic_string(dynamic_string *ds, const char *to_copy)
  {
  fprintf(stderr, "The call to copy_to_end_of_dynamic_string needs to be mocked!!\n");
  exit(1);
  }

int diswul(struct tcp_chan * chan, unsigned long value)
  {
  fprintf(stderr, "The call to diswul needs to be mocked!!\n");
  exit(1);
  }

int rpp_eom(int index)
  {
  fprintf(stderr, "The call to rpp_eom needs to be mocked!!\n");
  exit(1);
  }

resource *find_resc_entry(pbs_attribute *pattr, resource_def *rscdf)
  {
  fprintf(stderr, "The call to find_resc_entry needs to be mocked!!\n");
  exit(1);
  }

job *mom_find_job(char *jobid)
  {
  fprintf(stderr, "The call to find_job needs to be mocked!!\n");
  exit(1);
  }

#undef diswsi
int diswsi(int stream, int value)
  {
  fprintf(stderr, "The call to diswsi needs to be mocked!!\n");
  exit(1);
  }

job *job_alloc(void )
  {
  fprintf(stderr, "The call to job_alloc needs to be mocked!!\n");
  exit(1);
  }

#undef disrsi
int disrsi(struct tcp_chan * chan, int *retval)
  {
  *retval = 1;
  return 0;
  }

int timeval_subtract(struct timeval *result, struct timeval *x, struct timeval *y)
  {
  fprintf(stderr, "The call to timeval_subtract needs to be mocked!!\n");
  exit(1);
  }

int allocate_demux_sockets(job *pjob, int flag)
  {
  fprintf(stderr, "The call to allocate_demux_sockets needs to be mocked!!\n");
  exit(1);
  }

int kill_job(job *pjob, int sig, const char *killer_id_name, const char *why_killed_reason)
  {
  fprintf(stderr, "The call to kill_job needs to be mocked!!\n");
  exit(1);
  }

int add_to_resend_things(resend_momcomm *mc)
  {
  fprintf(stderr, "The call to add_to_resend_things needs to be mocked!!\n");
  exit(1);
  }

im_compose_info *create_compose_reply_info(char *jobid, char *cookie, hnodent *np, int command, tm_event_t event, tm_task_id taskid)
  {
  fprintf(stderr, "The call to create_compose_reply_info needs to be mocked!!\n");
  exit(1);
  }

int get_hostaddr_hostent_af(int *local_errno, char *hostname, unsigned short *af_family, char **host_addr, int *host_addr_len)
  {
  fprintf(stderr, "The call to get_hostaddr_hostent_af needs to be mocked!!\n");
  exit(1);
  }

pid_t fork_me(int conn) 
  {
  return(0);
  }

void DIS_tcp_close(struct tcp_chan *chan) {}

void DIS_tcp_cleanup(struct tcp_chan *chan) {}

void free_dynamic_string(dynamic_string *ds) {}

ssize_t write_ac_socket(int fd, const void *buf, ssize_t count)
  {
  return(0);
  }

ssize_t read_ac_socket(int fd, void *buf, ssize_t count)
  {
  return(0);
  }
