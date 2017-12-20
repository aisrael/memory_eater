# memory_eater
A small C program and Dockerfile that will keep trying to allocate memory until it exhausts available memory. Used to exercise and demonstrate `cgroups` and Docker/Kubernetes container resource limits. Also acts as an example for Docker multi-stage builds.

### Try it

```
$ docker run --rm -t -m 4m --memory-swap 4m aisrael/memory_eater
page_size => 4096
avphys_pages => 205726
availMem => 842653696
Allocated 1 MB
Allocated 2 MB
Allocated 3 MB
```
