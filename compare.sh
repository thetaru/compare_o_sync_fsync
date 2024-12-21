#!/bin/bash

# clear cache
echo 1 > /proc/sys/vm/drop_caches

gcc -o o_sync src/o_sync.c
./o_sync "test_sync.txt"

# clear cache
echo 1 > /proc/sys/vm/drop_caches

gcc -o fsync src/fsync.c
./fsync "test_fsync.txt"

rm -f test_fsync.txt test_sync.txt
rm -f o_sync fsync
