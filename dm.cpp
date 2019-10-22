
#include <stdio.h>

const char * input = "input.txt";

int initT (int taskNum, int (*taskInfo)[3]){
    int i;
    int result = 0;

    for (i=taskNum; i>=0; i--){
        result += taskInfo[i][0];
    }
    return result;
}

int interfere(int taskNum, int (*taskInfo)[3], int t){
    int i;
    int result = 0;

    if ( taskNum == 0 )
        return result;

    for(i=taskNum-1; i>=0; i--){
        int T = taskInfo[i][2];
        int C = taskInfo[i][0];
        int tmp = t/T;

     
        if ( t%T > 0)
            tmp += 1;

        result += tmp * C;
    }
    return result;
}

int newT (int taskNum, int (*taskInfo)[3], int t){
    return interfere(taskNum, taskInfo, t) + taskInfo[taskNum][0];
}

int IsResponstime (int computation, int taskNum, int t, int (*taskInfo)[3]){
    if ( computation+interfere(taskNum, taskInfo, t) == t)
        return 1;
    return 0;
}



void insertSort(int taskNum, int (*taskInfo)[3], int computation, int deadline, int period){
    int i;

    
    if (taskNum == 0){
        taskInfo[0][0] = computation;
        taskInfo[0][1] = deadline;
        taskInfo[0][2] = period;
    }

   
    else{
        for (i=taskNum; i>0; i--){
            if (deadline < taskInfo[i-1][1]){
                taskInfo[i][0] = taskInfo[i-1][0];
                taskInfo[i][1] = taskInfo[i-1][1];
                taskInfo[i][2] = taskInfo[i-1][2];
            }

            else
                break;
        }

        taskInfo[i][0] = computation;
        taskInfo[i][1] = deadline;
        taskInfo[i][2] = period;
    }
}

int main(void) {
    freopen(input, "r", stdin);
	setbuf(stdout, NULL);

	int n, tmp_c, tmp_d, tmp_p;
	int taskNum;

	
	scanf("%d", &n);
	int taskInfo[n][3];

	for(taskNum = 0; taskNum < n; taskNum++) {
        scanf("%d", &tmp_c);
        scanf("%d", &tmp_d);
        scanf("%d", &tmp_p);
        insertSort(taskNum, taskInfo, tmp_c, tmp_d, tmp_p);
	}

	printf(" the result in order with Deadline\n");
    printf("Task Table\n");
	for (taskNum=0; taskNum <n; taskNum++){
        printf("Task %d = (%d, %d, %d)\n",taskNum+1, taskInfo[taskNum][0], taskInfo[taskNum][1],taskInfo[taskNum][2]);
	}
	printf("\n");
	printf("Task Number : Response time , Schedulable\n\n");

	
	for(taskNum = 0; taskNum < n; taskNum++){
       
        int t = initT(taskNum, taskInfo);
        int D = taskInfo[taskNum][1];
        char s;

   
        while (!IsResponstime(taskInfo[taskNum][0], taskNum, t, taskInfo)){
            t = newT(taskNum, taskInfo, t);
            if ( t < 0 ){
                t = -1;
                break;
            }
        }

       
        if ( t > D || t == -1)
            s = 'X';
        else
            s = 'O';

        printf("Task %d : %d , %c\n", taskNum+1, t, s);

	}


	return 0;
}

