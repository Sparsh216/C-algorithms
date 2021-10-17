void getUniqueNumbers()
{
  struct process p;       // We need only 1 structure
  size_t counter = 0;     // sample counter
  int    oddEven;         // flag if we are parent
  pid_t pid = fork();     // Fork here
  if (-1 == pid)
  {
    abort(); // simply die on error
  }

  oddEven = 0 == pid ? 0 : 1;
  p.processId = getpid(); // We are either child or parent.

  while (counter < numLimit)
  {
    int numberFromFile = getNumberFromFile();
    if ((numberFromFile & 1) == oddEven)
    {
      p.numbers[counter++] = numberFromFile;
      printf("N: %d, PID: %ld\n", numberFromFile, (long)p.processId);
      numberFromFile++;
      writeNumberToFile(numberFromFile);
    }
    sleep(1); // sleep in both cases
    // Extra check for parent: if child has died, we are in infinite
    // loop, so check it here
    if (0 != pid && counter < numLimit)
    {
      int status = 0;
      if (waitpid(pid, &status, WNOHANG) > 0)
      {
        printf("Child exited with 0x%08X status\n", status);
        break;
      }
    }
  }

  // wait till child process terminates
  if (0 != pid)
  {
    int status = 0;
    waitpid(pid, &status, 0);
    printf("Child exited with 0x%08X status\n", status);
  }
}
