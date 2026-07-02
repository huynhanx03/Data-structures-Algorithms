#!/bin/bash

# Build the docker image
echo "🚀 Building Docker image..."
docker build -t codecommit -f CodeCommit/Dockerfile CodeCommit/

# Run the container
echo "🚀 Running sync process..."
docker run --rm \
  -v "$PWD:/app" \
  -w /app \
  -e LEETCODE_SESSION="$LEETCODE_SESSION" \
  -e LEETCODE_CSRF="$LEETCODE_CSRF" \
  -e SYNC_SINCE="$SYNC_SINCE" \
  codecommit
