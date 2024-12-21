# compare o_sync fsync
o_syncの方は、ディスクの書き込みを待つ分遅くなっていることがわかる。
```sh
./compare.sh
```
```
Time taken with o_sync: 33.288000 msec
Time taken with fsync: 2.575000 msec
```
