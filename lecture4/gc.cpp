#include <iostream>
#include <cassert>

typedef struct data_t{
  int d1;
  int d2;
  char c[256];
} data;

const int TOTAL_DATA = 1000;
const int EVENTS = 50;
int current_data = 0;
data *pool;

data* get_next_data()
{
  assert(current_data < TOTAL_DATA);
  return pool[current_data++];
}

void send_data(data *d)
{
  // Pretend network stuff
}

int main()
{
  pool = new data[TOTAL_DATA];

  while(true){
    // Need to send EVENTS in a timely manner
    // Will this loop work?
    for(int c = 0; c < EVENTS; c++){
      data* d = get_next_data();
      send_data(d);
      delete d;
    }
  }

  delete [] pool;

  return 0;
}
