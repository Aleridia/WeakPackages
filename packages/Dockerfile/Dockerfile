# Using a base image without specifying a tag
FROM ubuntu

# Installing packages without cleaning up the cache and without using a package manager's update
RUN apt-get install -y python3

#Use update alone
RUN apt-get update

# Running as the root user
USER root

# Copying files with absolute paths and wildcard characters
COPY /source_code/* /app/

# Using the ADD command to download and extract a tarball from a potentially insecure URL
ADD http://example.com/bigfile.tar.gz /bigfile/

# Executing commands with multiple RUN statements and creating large image layers
RUN mkdir /data
RUN echo "Hello World" > /data/hello.txt
RUN apt-get install -y curl
RUN curl http://example.com/somescript.sh | sh

# Exposing all ports without specifying protocols
EXPOSE 80
EXPOSE 443
EXPOSE 8080

# Using both CMD and ENTRYPOINT together and overriding ENTRYPOINT with CMD
ENTRYPOINT ["python3", "/app/main.py"]
CMD ["--help"]

# No non-root USER specified
# No health check
# No volumes specified for persistent storage