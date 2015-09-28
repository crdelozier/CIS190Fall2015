int (){
  // int **twod = new int[10][10];
  int **twod = new int*[10];

  for(int c = 0; c < 10; c++){
    twod[c] = new int[10];
  }

  twod[1][2] = 5;

  for(int c = 0; c < 10; c++){
    delete [] twod[c];
  }
  delete [] twod;

  return 0;
}
