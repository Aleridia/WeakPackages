# Dockerfile
## How to run
To build the image, be in the [Dockerfile](.) folder : `docker -D build -t image .`
To extract the image : 
- `xz --decompress image.tar.xz`
- `docker load < image.tar`

To save the image : `docker save image | xz > image.tar.xz`

To pull the image : `docker push aleridia/weakpackage`

## Explaination
### What is bad in this Dockerfile
The provided Dockerfile is bad. Here are the reasons :

1. Using a base image without specifying a tag (latest is implicit),
2. Pin versions of apt-get install,
3. `/var/lib/apt/lists/*` not deleted after use of apt-get,
4. Installing packages without cleaning up the package cache (apt-get clean),
5. Running the image as the root user,
7. Using wildcard characters in COPY, which can be unpredictable,
8. Using ADD instead of COPY for local files,
9. Downloading and extracting files from an insecure URL with ADD,
10. Using multiple RUN instructions instead of a single one to minimize layers,
11. Exposing ports without specifying protocols,
12. Using both CMD and ENTRYPOINT, which can create unpredictable behavior,
13. Not using `-o pipefail` before RUN with a pip,
14. Not avoinding the installation of additional packages,
15. Update is used alone.

### Hadolint rules Coverage
1. DL3006
2. DL3008
3. DL3009
5. DL3002
10. DL3059
13. DL4006
14. DL3015

### Custom rules
So we need to write some custom rules to cover all the weaknesses.

4. Remove apt-cache with apt-clean (warning)
7. Don't use wildcard character in COPY (info)
8. Use COPY instead of ADD (error)
9. Use insecure URL (warning)
11. Exposing port without giving protocol (warning)
12. Use CMD and ENTRYPOINT (warning)
15. Not use update alone (error)


