#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"
#include "sync.h"

using namespace std;

static void agent(Sync *[]);

int
main(void) {

  Sync *sems[nSEM];

  try {
    for (int i = 0; i < nSEM; ++i) {
      sems[i] = Sync::open(names[i]);
    }
  }
  catch(SynException& se) {
    cerr << "Error openning semaphores"
	 << endl;
    return EXIT_FAILURE;
  }

  agent(sems);

  return EXIT_SUCCESS;
}


static void agent(Sync *sems[]) {

  for (;;) {
    cout << "Offering" << endl;
    int smoker = rand() % 3;
    sems[smoker]->signal();
    sems[nSEM - 1]->wait();
  }
}
