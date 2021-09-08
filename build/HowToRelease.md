<a id="top"></a>
# How To Release

## Update ApprovalTests.cpp.qt

Preparation:

- Check out revision `d45991b26d07ee391a90017c7c52301348ef48a6` of [ApprovalTests.cpp](https://github.com/approvals/ApprovalTests.cpp), along side this project
- Run the appropriate deploy_*_release.py

## Notes

* Markdownsnippets files here still have separate .source.md files, in mdsource directories
* We can't remove .source.md files until we have removed dependency on an old version of build scripts in ApprovalTests.cpp
