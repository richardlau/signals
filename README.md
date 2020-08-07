# SA_RESETHANDLER test

## Build

```console
$ make
```

## Run

On AIX it looks like the signal handler doesn't get the expected signal in the second argument (`siginfo_t*`) if the signal handler is installed with `SA_RESETHANDLER`.
``` console
$ ./signals
raise SIGUSR1 signal
signo 30 si_signo 0 si_code 0
$
```

## Expected behaviour

Expect the `si_signo` field of the second argument to be equal to the first argument.

### IBM i
```console
$ ./signals
raise SIGUSR1 signal
signo 30 si_signo 30 si_code 0
$
```

### Linux
```console
$ ./signals
raise SIGUSR1 signal
signo 10 si_signo 10 si_code 0
$
```

### z/OS
```console
>./signals
raise SIGUSR1 signal
signo 16 si_signo 16 si_code 0
>
```
