/*@ begin PerfTuning (
 def build {
  arg build_command = 'gcc -O0';
 }
 def performance_counter {
  arg method = 'basic timer';
  arg repetitions = 10;
 }
 def performance_params {
  param UF[] = range(1, 33);
 }

 def input_params {
  param N[] = [100000000];
 }

 def input_vars {
  decl double a1 = random;
  decl double a2 = random;
  decl double a3 = random;
  decl static double y[N] = 0;
  decl static double x1[N] = random;
  decl static double x2[N] = random;
  decl static double x3[N] = random;
 }

 def search {
  arg algorithm = 'Randomsearch';
  arg time_limit = 10;
  arg total_runs = 10;
 }
) @*/
/**-- (Generated by Orio) 
Best performance cost: 
  [0.239315, 0.187971, 0.187215, 0.187876, 0.188859, 0.187122, 0.188541, 0.187265, 0.188467, 0.18826] 
Tuned for specific problem sizes: 
  N = 100000000 
Best performance parameters: 
  UF = 25 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
        y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
for (int loop_loop_38=0; loop_loop_38 < 1; loop_loop_38++)  {
    int i;
    for (i = 0; i <= N - 25; i = i + 25) {
      y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
      y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
      y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
      y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
      y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
      y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
      y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
      y[(i + 7)] = y[(i + 7)] + a1 * x1[(i + 7)] + a2 * x2[(i + 7)] + a3 * x3[(i + 7)];
      y[(i + 8)] = y[(i + 8)] + a1 * x1[(i + 8)] + a2 * x2[(i + 8)] + a3 * x3[(i + 8)];
      y[(i + 9)] = y[(i + 9)] + a1 * x1[(i + 9)] + a2 * x2[(i + 9)] + a3 * x3[(i + 9)];
      y[(i + 10)] = y[(i + 10)] + a1 * x1[(i + 10)] + a2 * x2[(i + 10)] + a3 * x3[(i + 10)];
      y[(i + 11)] = y[(i + 11)] + a1 * x1[(i + 11)] + a2 * x2[(i + 11)] + a3 * x3[(i + 11)];
      y[(i + 12)] = y[(i + 12)] + a1 * x1[(i + 12)] + a2 * x2[(i + 12)] + a3 * x3[(i + 12)];
      y[(i + 13)] = y[(i + 13)] + a1 * x1[(i + 13)] + a2 * x2[(i + 13)] + a3 * x3[(i + 13)];
      y[(i + 14)] = y[(i + 14)] + a1 * x1[(i + 14)] + a2 * x2[(i + 14)] + a3 * x3[(i + 14)];
      y[(i + 15)] = y[(i + 15)] + a1 * x1[(i + 15)] + a2 * x2[(i + 15)] + a3 * x3[(i + 15)];
      y[(i + 16)] = y[(i + 16)] + a1 * x1[(i + 16)] + a2 * x2[(i + 16)] + a3 * x3[(i + 16)];
      y[(i + 17)] = y[(i + 17)] + a1 * x1[(i + 17)] + a2 * x2[(i + 17)] + a3 * x3[(i + 17)];
      y[(i + 18)] = y[(i + 18)] + a1 * x1[(i + 18)] + a2 * x2[(i + 18)] + a3 * x3[(i + 18)];
      y[(i + 19)] = y[(i + 19)] + a1 * x1[(i + 19)] + a2 * x2[(i + 19)] + a3 * x3[(i + 19)];
      y[(i + 20)] = y[(i + 20)] + a1 * x1[(i + 20)] + a2 * x2[(i + 20)] + a3 * x3[(i + 20)];
      y[(i + 21)] = y[(i + 21)] + a1 * x1[(i + 21)] + a2 * x2[(i + 21)] + a3 * x3[(i + 21)];
      y[(i + 22)] = y[(i + 22)] + a1 * x1[(i + 22)] + a2 * x2[(i + 22)] + a3 * x3[(i + 22)];
      y[(i + 23)] = y[(i + 23)] + a1 * x1[(i + 23)] + a2 * x2[(i + 23)] + a3 * x3[(i + 23)];
      y[(i + 24)] = y[(i + 24)] + a1 * x1[(i + 24)] + a2 * x2[(i + 24)] + a3 * x3[(i + 24)];
    }
    for (i = N - ((N - (0)) % 25); i <= N - 1; i = i + 1) 
      y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
  }
/*@ end @*/

/*@ end @*/
