# Multistage builds FTW
FROM gcc:7.2 as gcc
COPY memory_eater.c .
RUN gcc -o memory_eater -static memory_eater.c

FROM alpine:3.6
WORKDIR /usr/src
COPY --from=gcc memory_eater /usr/src
CMD ["/usr/src/memory_eater"]
