#!/bin/bash


set -x

cat /sys/fs/cgroup/memory/memory.stat
cat /sys/fs/cgroup/memory/memory.soft_limit_in_bytes
cat /sys/fs/cgroup/memory/memory.limit_in_bytes

CGROUP_MEM_LIMIT_BYTES=$(cat /sys/fs/cgroup/memory/memory.limit_in_bytes)


ulimit -v $[CGROUP_MEM_LIMIT_BYTES / 1024 + 3182]
ulimit -a

./test_mem_lim



