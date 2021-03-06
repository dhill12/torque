#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h> /* fprintf */
#include <time.h> /* timeval */
#include <pthread.h> /* pthread_mutex_t */

#include "attribute.h" /* attribute_def, svrattrl, pbs_attribute */
#include "net_connect.h" /* pbs_net_t, conn_type */
#include "server_limits.h" /* RECOV_WARM */
#include "work_task.h" /* work _task, work_type, all_tasks */
#include "server.h" /* server */
#include "sched_cmds.h" /* SCH_SCHEDULE_NULL */
#include "batch_request.h" /* batch_request */
#include "array.h" /* job_array */
#include "pbs_job.h" /* job */
#include "node_func.h" /* node_info */
#include "list_link.h" /* list_link */
#include "pbs_ifl.h" /* batch_op */
#include "array.h" /* ArrayEventsEnum */
#include "pbs_nodes.h" /* pbsnode */
#include "queue.h" /* pbs_queue */



const char *msg_momnoexec2 = "Job cannot be executed\nSee job standard error file";
const char *msg_job_end_sig = "Terminated on signal %d";
const char *msg_obitnojob  = "Job Obit notice received from %s has error %d";
attribute_def job_attr_def[10];
const char *msg_obitnocpy = "Post job file processing error; job %s on host %s";
int   server_init_type = RECOV_WARM;
char *path_spool;
const char *msg_init_abt = "Job aborted on PBS Server initialization";
pbs_net_t pbs_server_addr;
const char *PJobState[] = {"hi", "hello"};
struct server server;
int  svr_do_schedule = SCH_SCHEDULE_NULL;
int listener_command = SCH_SCHEDULE_NULL;
int LOGLEVEL = 10;
const char *msg_obitnodel = "Unable to delete files for job %s, on host %s";
const char *msg_momnoexec1 = "Job cannot be executed\nSee Administrator for help";
const char *msg_job_end_stat = "Exit_status=%d";
const char *msg_momjoboverlimit = "Job exceeded some resource limit (walltime, mem, etc.). Job was aborted\nSee Administrator for help";
pthread_mutex_t *svr_do_schedule_mutex;
pthread_mutex_t *listener_command_mutex;
extern int alloc_br_null;
int bad_connect;
int bad_job;
int bad_queue;
int double_bad;
int cray_enabled;
int reported;
int bad_drequest;


struct batch_request *alloc_br(int type)
  {
  batch_request *preq;
  if (alloc_br_null)
    return(NULL);

  preq = (batch_request *)calloc(1, sizeof(batch_request));
  preq->rq_type = type;

  return(preq);
  }

job_array *get_jobs_array(job **pjob)
  {
  fprintf(stderr, "The call to get_jobs_array to be mocked!!\n");
  exit(1);
  }

char *parse_servername(char *name, unsigned int *service)
  {
  return(strdup(name));
  }

int job_save(job *pjob, int updatetype, int mom_port)
  {
  return(0);
  }

int svr_job_purge(job *pjob)
  {
  return(0);
  }

void svr_mailowner(job *pjob, int mailpoint, int force, const char *text) {}

int modify_job_attr(job *pjob, svrattrl *plist, int perm, int *bad)
  {
  fprintf(stderr, "The call to modify_job_attr to be mocked!!\n");
  exit(1);
  }

pbs_net_t get_hostaddr(int *local_errno, char *hostname)
  {
  return(0);
  }

long attr_ifelse_long(pbs_attribute *attr1, pbs_attribute *attr2, long deflong)
  {
  return(0);
  }

pbs_queue *get_jobs_queue(job **pjob)
  {
  static pbs_queue bob;

  if (bad_queue)
    {
    return(NULL);
    }
  else if (double_bad)
    {
    *pjob = NULL;
    return(NULL);
    }

  return(&bob);
  }

void reply_ack(struct batch_request *preq)
  {
  fprintf(stderr, "The call to reply_ack to be mocked!!\n");
  exit(1);
  }

void cleanup_restart_file( job *pjob)  
  {
  fprintf(stderr, "The call to cleanup_restart_file to be mocked!!\n");
  exit(1);
  }

void release_req(struct work_task *pwt)
  {
  fprintf(stderr, "The call to release_req to be mocked!!\n");
  exit(1);
  }

void free_nodes(node_info **ninfo_arr) {}

void free_br(struct batch_request *preq) {}

void remove_job_delete_nanny( struct job *pjob)
  {
  fprintf(stderr, "The call to remove_job_delete_nanny to be mocked!!\n");
  exit(1);
  }

void account_jobend( job *pjob, char *used) 
  {
  fprintf(stderr, "The call to account_jobend to be mocked!!\n");
  exit(1);
  }

struct work_task *set_task(enum work_type type, long event_id, void (*func)(), void *parm, int get_lock)
  {
  return(NULL);
  }

void svr_disconnect(int handle)
  {
  fprintf(stderr, "The call to svr_disconnect to be mocked!!\n");
  exit(1);
  }

void req_reject(int code, int aux, struct batch_request *preq, const char *HostName, const char *Msg)
  {
  fprintf(stderr, "The call to req_reject to be mocked!!\n");
  exit(1);
  }

int depend_on_term(char *job_id)
  {
  return(0);
  }

void *get_next(list_link pl, char *file, int line)
  {
  fprintf(stderr, "The call to get_next to be mocked!!\n");
  exit(1);
  }

int issue_Drequest(int conn, struct batch_request *request, void (*func)(struct work_task *), struct work_task **ppwt)
  {
  if (bad_drequest)
    return(-1);

  return(0);
  }

void set_resc_assigned(job *pjob, enum batch_op op) {}

void update_array_values(job_array *pa, int old_state, enum ArrayEventsEnum event, char *job_id, long job_atr_hold, int job_exit_status)
  {
  fprintf(stderr, "The call to update_array_values to be mocked!!\n");
  exit(1);
  }

void append_link(tlist_head *head, list_link *new_link, void *pobj)
  {
  if (pobj != NULL)
    {
    new_link->ll_struct = pobj;
    }
  else
    {
    /* WARNING: This mixes list_link pointers and ll_struct
         pointers, and may break if the list_link we are operating
         on is not the first embeded list_link in the surrounding
         structure, e.g. work_task.wt_link_obj */

    new_link->ll_struct = (void *)new_link;
    }

  new_link->ll_prior = head->ll_prior;

  new_link->ll_next  = head;
  head->ll_prior = new_link;
  new_link->ll_prior->ll_next = new_link; /* now visible to forward iteration */
  }

int svr_connect(pbs_net_t hostaddr, unsigned int port, struct pbsnode *pnode, void *(*func)(void *), enum conn_type cntype)
  {
  if (bad_connect)
    return(-1);

  return(1);
  }

void issue_track(job *pjob) {}

int svr_setjobstate(job *pjob, int newstate, int newsubstate, int  has_queue_mute)
  {
  pjob->ji_qs.ji_state = newstate;
  pjob->ji_qs.ji_substate = newsubstate;
  return(0);
  }

job *svr_find_job(char *jobid, int get_subjob)
  {
  job *pjob = NULL;

  if (bad_job == 0)
    {
    pjob = calloc(1, sizeof(*pjob));
    if (jobid != NULL)
      {
      strncpy(pjob->ji_qs.ji_jobid, jobid, sizeof(pjob->ji_qs.ji_jobid)-1);
      }
    pjob->ji_wattr[JOB_ATR_reported].at_flags = ATR_VFLAG_SET;
  
    if (reported)
      pjob->ji_wattr[JOB_ATR_reported].at_val.at_long = 1;
    }

  return(pjob);
  }

int timeval_subtract(struct timeval *result, struct timeval *x, struct timeval *y)
  {
  return(0);
  }

int unlock_queue(struct pbs_queue *the_queue, const char *method_name, const char *msg, int logging)
  {
  return(0);
  }

void svr_evaljobstate(job *pjob, int *newstate, int *newsub, int forceeval)
  {
  fprintf(stderr, "The call to svr_evaljobstate to be mocked!!\n");
  exit(1);
  }

int insert_task(all_tasks *at, work_task *wt) 
  {
  fprintf(stderr, "The call to insert_task to be mocked!!\n");
  exit(1);
  }

void get_jobowner(char *from, char *to)
  {
  strcpy(to, "dbeer");
  }


char *threadsafe_tokenizer(char **str, const char *delims)
  {
  fprintf(stderr, "The call to threadsafe_tokenizer needs to be mocked!!\n");
  exit(1);
  }

int get_svr_attr_l(int index, long *l)
  {
  if (cray_enabled)
    *l = 1;

  return(0);
  }

int safe_strncat(char *str, char *to_append, size_t space_remaining)
  {
  return(0);
  }

void close_conn(int sd, int mutex)
  {
  fprintf(stderr, "The call to close_conn needs to be mocked!!\n");
  exit(1);
  }

batch_request *get_remove_batch_request(

  char *br_id)

  {
  return(NULL);
  }

int get_batch_request_id(

  batch_request *preq)

  {
  return(0);
  }

int unlock_ji_mutex(job *pjob, const char *id, const char *msg, int logging)
  {
  return(0);
  }

int lock_ji_mutex(job *pjob, const char *id, char *msg, int logging)
  {
  return(0);
  }

struct pbsnode *find_nodebyname(

  const char *nodename) /* I */

  {
  return(NULL);
  }

int kill_job_on_mom(

  char           *jobid,
  struct pbsnode *pnode)

  {
  return(0);
  }

int unlock_node(
    
  struct pbsnode *the_node,
  const char     *id,
  char           *msg,
  int             logging)

  {
  return(0);
  }

int unlock_ai_mutex(job_array *pa, const char *id, char *msg, int logging)
  {
  return(0);
  }

int record_job_as_exiting(job *pjob)
  {
  return(0);
  }

int remove_job_from_exiting_list(job *pjob)
  {
  return(0);
  }

void log_event(int eventtype, int objclass, const char *objname, const char *text)
  {
  }

