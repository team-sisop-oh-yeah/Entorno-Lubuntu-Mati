IMAGE_NAME:=manu-cproject
TAG_VERSION=1.0
MAINTAINER=neverkas
CONTAINER=$(MAINTAINER)/$(IMAGE_NAME):$(TAG_VERSION)

SEC_FLAGS_C:=--cap-add=SYS_PTRACE --security-opt seccomp=unconfined
