#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h> /* fprintf */

#include "server.h" /* server */
#include "batch_request.h" /* batch_request */
#include "pbs_job.h" /* job */

char server_name[PBS_MAXSERVERNAME + 1];
struct server server;
int LOGLEVEL = 7; /* force logging code to be exercised as tests run */

int reply_send_svr(struct batch_request *request)
  {
  fprintf(stderr, "The call to reply_send_svr to be mocked!!\n");
  exit(1);
  }

void req_reject(int code, int aux, struct batch_request *preq, const char *HostName, const char *Msg)
  {
  fprintf(stderr, "The call to req_reject to be mocked!!\n");
  exit(1);
  }

job *svr_find_job(char *jobid, int get_subjob)
  {
  fprintf(stderr, "The call to find_job to be mocked!!\n");
  exit(1);
  }


int unlock_ji_mutex(job *pjob, const char *id, const char *msg, int logging)
  {
  return(0);
  }
