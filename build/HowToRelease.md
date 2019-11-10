<a id="top"></a>
# How To Release

## Update ApprovalTests.cpp.qt

Preparation:

- [ ] Push all changes
- [ ] Check that the [builds are passing](https://github.com/approvals/ApprovalTests.cpp.qt/commits/master)
- [ ] Write summary of changes since last release, based on changes since [the last release](https://github.com/approvals/ApprovalTests.cpp.qt/releases)
- [ ] Determine the semantic version number
- [ ] Update the version number in [build_hpp.sh](/build/build_hpp.sh)
- [ ] On the features page, add the line `## [new version number]` after `## vNext`

Creating the Build

- [ ] Run `build_hpp.sh`

Publishing

- [ ] Commit and push `ApprovalTests.cpp.qt`
- [ ] Finish off the upload to github, by uploading the new .hpp, pasting in the release notes, and hitting "Publish release"
- [ ] Finish off the release Tweet
- [ ] Close any [Issues](https://github.com/approvals/ApprovalTests.cpp.qt/issues) that were resolved in this release

Prepare for next release

- [ ] Change version number to current version number, and new version number to `$UNSET_VERSION`
- [ ] Make sure the release notes named with the new version exist
- [ ] `cp relnotes_template.md relnotes_X.X.X.md`
