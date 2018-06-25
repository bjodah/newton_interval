#include "newton_interval.h"
#include "unittest.h"

#include <stdio.h>

int test1(){
  const int nt = 4;
  double t[] = {0.0,1.0,2.0,3.0};
  double treq = 0.5;
  int i=-2;
  i=(int)get_interval(t, nt, treq);
  return (i == 0);
}

int test2(){
  const int nt = 2;
  double t[] = {0.0,1.0};
  double treq = 0.5;
  int i=-2;
  i=(int)get_interval(t, nt, treq);
  return (i == 0);
}

int test3(){
  const int nt = 3;
  double t[] = {0.0,1.0,2.0};
  double treq = 0.9;
  int i=-2;
  i=(int)get_interval(t, nt, treq);
  return (i == 0);
}

int test4(){
  const int nt = 3;
  double t[] = {0.0,1.0,2.0};
  double treq = -0.9;
  int i=-2;
  i=(int)get_interval(t, nt, treq);
  return (i == -1);
}

#define NT 50
int test5(){
  const int nt = NT;
  double t[NT];
  double treq = 10.0;
  int j;
  int i = -2;
  int ti = nt-2;
  for(j = 0; j<nt; ++j)
    t[j] = j*treq/(nt-1);
  i=get_interval_from_guess(t, nt, treq, ti);
  return (i==49);
}

int test6(){
    int i;
    const int N = 3;
    double x[3] = {0.0, 1.0, 2.0};
    i = get_interval_from_guess(x, N, 1.25, 0);
    return (i==1);
}

int test7(){
  const int nt = NT;
  double t[NT] = {0.013921575895562895, 0.1042735832107497, 0.25215887627910727, 0.31241134057077979, 
  0.41974237995332697, 0.51719529205145565, 0.66303332869309528, 0.76229828678918832, 
  0.87558296540762126, 0.97386245191530763, 1.0377896661519703, 1.1889680133229692, 1.2416527328665417, 
  1.338062808838107, 1.4633032586712158, 1.5796272634683646, 1.6379715301726725, 1.774529049741536, 
  1.8400243194517836, 1.9981992968991515, 2.0684186604503583, 2.1698021595633508, 2.266587232107339, 
  2.3844438469587352, 2.5095650429270533, 2.6048461656562512, 2.6811483557764682, 2.7935583517155593, 
  2.9067561403119644, 2.9862933343637836, 3.0977471246145982, 3.1929231785498211, 3.2736602326142874, 
  3.374407501920567, 3.5026461018784718, 3.589726609710818, 3.6781749315581993, 3.8002925291316996, 
  3.8917132327331769, 4.0412022038408884, 4.0964051336342706, 4.2082190298322217, 4.2972308344524128, 
  4.4138730264013164, 4.4964256651412864, 4.6420434334800227, 4.7022090925723381, 4.8483483817556854, 
  4.9055686924929454, 5.0453687429803713};
  double treq = 0.1212686567164179;
  int i = -2;
  int ti = 25;
  i = get_interval_from_guess(t, nt, treq, ti);
  return (i==1);
}


#define NTESTS 7
static const TestCase t1 = {test1, "test1"};
static const TestCase t2 = {test2, "test2"};
static const TestCase t3 = {test3, "test3"};
static const TestCase t4 = {test4, "test4"};
static const TestCase t5 = {test5, "test5"};
static const TestCase t6 = {test6, "test6"};
static const TestCase t7 = {test7, "test7"};
static const TestCase* test_cases[NTESTS] = {&t1, &t2, &t3, &t4, &t5, &t6, &t7};

int main(int argc, char ** argv){
    if (argc != 1){
        return 1;
    }
    return run_tests(NTESTS, test_cases, argv[0]);
}
