# WeakPackage for Java

## How to run app
1. Install maven
2. Build `mvn package` 
3. Run `java -cp target/WeakPackage-1.0-SNAPSHOT.jar WeakPackageId.App`

## Weaknesses
- CWE-79: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting') -> XSSExample.java
- CWE-502: Deserialization of Untrusted Data -> InsecureDeserialization.java
- CWE-269: Improper Privilege Management -> PrivilegeUse.java
- Bad dependency (log4j)

