# @file      release.sh
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#
# README: https://gitlab.igg.uni-bonn.de/help/api/releases/index.md

PROJECT_ID=853

# POST
curl --header 'Content-Type: application/json' \
  --header "PRIVATE-TOKEN: $IGG_GITLAB_TOKEN" \
  --data-binary "@release_data.json" \
  --request POST https://gitlab.igg.uni-bonn.de/api/v4/projects/$PROJECT_ID/releases/
