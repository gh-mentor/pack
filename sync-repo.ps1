# This bash script uses git to synchronize changes between the local and remote GitHub repository.

# steps:
# 1. pull changes from remote repository
# 2. stage all changes
# 3. commit changes with message 'Updated'
# 4. push changes to remote repository on branch 'main'.

# pull changes from remote repository
git pull origin main

# stage all changes
git add .

# commit changes with message 'Updated'
git commit -m "Updated"

# push changes to remote repository on branch 'main'
git push origin main

# echo a message to the terminal window
Write-Output "Changes synchronized between local and remote repository."



