## Build & run
- `cmake . .`
- `make`
- ./vulnerable_project

## Vulnerabilities
- Buffer overflow : put string with more than 30 characters
- SQL injection : put "'; DROP TABLE users; --" in the input
- Bad dependency : OpenSSL 1.0.1