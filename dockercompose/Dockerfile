FROM ubuntu:22.04

RUN apt-get -y update &&  apt-get -y upgrade && apt-get -y install \
  bash\
  postfix\
  tmux\
  telnet\
  vim\
  curl

EXPOSE 25

COPY ./start.sh .

CMD ["/start.sh"]

