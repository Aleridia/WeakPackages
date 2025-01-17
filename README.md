## Run security tools
Security tools are randomly selected and inspired by security tools included in Gitlab ultimate (<3).
Feel free to add some if you want.

### Semgrep

- Run with docker : `sudo docker run -it -v "${PWD}/packages:/src" -v "${PWD}/results:/results" semgrep/semgrep semgrep scan --json-output=/results/semgrep-results.json`

### Gitleaks
Rules are default rules with additionnal coverage from [this project](https://github.com/Aleridia/secrets-patterns-db).

- Run with docker : `sudo docker run -v "${PWD}/packages:/src" -v "${PWD}/results:/results" -v "${PWD}/resources:/resources" zricethezav/gitleaks:latest dir -c /resources/gitleaks-rules.toml -f json -r /results/gitleaks-report.json /src`

### Hadolint
- Run with docker : `sudo docker run --rm -i hadolint/hadolint hadolint -f json - < packages/Dockerfile/Dockerfile > results/hadolint.json`