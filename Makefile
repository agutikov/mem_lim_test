

WORK_DIR := $(realpath ./)

DOCKER_MEM_LIM = 100m

DOCKER_RUN_OPTS := -v $(WORK_DIR):/work \
	--memory=$(DOCKER_MEM_LIM) \
	--log-driver=syslog


all:
	@echo "HELP:"



build:
	gcc test_mem_lim.c -o test_mem_lim
	docker build -t test_mem_lim ./


run:
	docker run $(DOCKER_RUN_OPTS) test_mem_lim runme.sh
	
	
docker_sh:
	docker run $(DOCKER_RUN_OPTS) --entrypoint=bash -it test_mem_lim 

