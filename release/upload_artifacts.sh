# @file      upload_artifacts.sh
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#
# https://docs.gitlab.com/ce/api/projects.html#upload-a-file

PROJECT_ID=853

# Download latest artifacts to your local machine:
curl --output artifacts.zip --header "PRIVATE-TOKEN: $IGG_GITLAB_TOKEN" \
  "https://gitlab.igg.uni-bonn.de/api/v4/projects/$PROJECT_ID/jobs/artifacts/master/download?job=build"

# Upload this artifacts, check for the output!!!
curl --header "PRIVATE-TOKEN: $IGG_GITLAB_TOKEN" \
  --form "file=@artifacts.zip" \
  "https://gitlab.igg.uni-bonn.de/api/v4/projects/$PROJECT_ID/uploads"

echo "\e[1m\e[93m===========================================================\
==========================================================================\e[0m"
echo "\e[1m\e[93mPLEASE MAKE SURE YOU COPY THE HASH NUMBER FROM THE MARKDOWN \
ENTRY AND UPDATE IT IN THE release_data.json FILE !! ...\e[0m"
echo "\e[1m\e[93mThis number should be something similar to \
\e[1m\e[36me550dfc73e150a3e43e6e530ff30212a ...\e[0m"
echo "\e[1m\e[93m===========================================================\
==========================================================================\e[0m"
