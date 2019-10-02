git status

git diff 128B-sxample.json

git checkout -- 128B-sxample.json

git diff testcases/2111/2111.json

git branch

git status

git add run_testcase.py testcases/2111/2111.json

git checkout ../p4-sdnet/src/soon_patch/soon_patch.p4

git commit -m "add dy_weight entry in json file"

git config --global user.email "siyiq@xilinx.com"

git config --global user.name "siyiq"

git remote -v

git remote add upstream https://gitenterprise.xilinx.com/XLAP/programmable-packet-scheduling.git

git fetch upstream

=============================
git merge upsteam/shaper

git reflog

git reset --hard 7b74eed

git log | less

git status

git diff ......file

git add ....file

git commit -m "add dynamic weight update support"

git checkout shaper

git push simulation
