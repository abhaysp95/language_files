# makie ubuntu as base image
FROM "ubuntu:latest"

# add docker as user
RUN useradd -d /home/docker -s /bin/bash docker
RUN su docker

# setting up logs for docker installation
ENV DIR_LOG_DOCKER="/root/logsDocker"
ENV INSTALL_LOG_DOCKER="/root/logsDocker/install_logs.log"

# create the log dir and folder
RUN mkdir -p "${DIR_LOG_DOCKER}"
RUN touch ${INSTALL_LOG_DOCKER}
RUN cat /etc/os-release | grep -i version | head -n 1 | grep -o "([A-Za-z0-9]\+\s[A-Za-z0-9]\+)" \
	| sed -e "s/^/\tCodeName: /" | tee -a ${INSTALL_LOG_DOCKER}
RUN echo "Log File and its directory created" | sed -e "s/^/$(date "+%Y-%m-%d %H:%M:%S") : /" 2>&1 \
	| tee -a ${INSTALL_LOG_DOCKER}


# Install the dependencies
RUN apt update | sed -e "s/^/$(date "+%Y-%m-%d %H:%M:%S") : /" 2>&1 | tee -a ${INSTALL_LOG_DOCKER} \
	&& apt install -y python3 python3-pip | sed -e "s/^/$(date "+%Y-%m-%d %H:%M:%S") : /" 2>&1 | tee -a ${INSTALL_LOG_DOCKER} \
	&& ln -s /usr/bin/python3 /usr/local/bin/python3 | sed -e "s/^/$(date "+%Y-%m-%d %H:%M:%S") : /" 2>&1 | tee -a ${INSTALL_LOG_DOCKER} \
	&& pip3 install --upgrade pip | sed -e "s/^/$(date "+%Y-%m-%d %H:%M:%S") : /" 2>&1 | tee -a ${INSTALL_LOG_DOCKER}

# working directory
WORKDIR /home/docker/python_work
