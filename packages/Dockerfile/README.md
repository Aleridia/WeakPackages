## Dockerfile
### What is bad in this Dockerfile
The provided Dockerfile is bad. Here are the reasons :

1. Using a base image without specifying a tag (latest is implicit).
2. No apt-get update before installing packages.
3. Installing packages without cleaning up the package cache (apt-get clean).
4. Running the image as the root user.
5. Using absolute paths in COPY and ADD commands.
6. Using wildcard characters in COPY, which can be unpredictable.
7. Using ADD instead of COPY for local files.
8. Downloading and extracting files from an insecure URL with ADD.
9. Using multiple RUN instructions instead of a single one to minimize layers.
10. Exposing ports without specifying protocols.
11. Using both CMD and ENTRYPOINT, which can create unpredictable behavior.
12. Not using `-o pipefail` before RUN with a pipe
13. Not avoinding the installation of additional packages
14. Update is used alone

### Hadolint rules Coverage
1. DL3006
2. DL3008
4. DL3002
9. DL3059
12. DL4006
13. DL3015

### Custom rules
So we need to write some custom rules to cover all the weaknesses.
3. Remove apt-cache with apt-clean (warning)
5. Don't use absolute path for COPY and ADD (warning)
6. Don't use wildcard character in COPY (info)
7. Use COPY instead of ADD (error)
8. Use insecure URL (warning)
10. Exposing port without giving protocol (warning)
11. Use CMD and ENTRYPOINT (warning)
14. Not use update alone (error)


