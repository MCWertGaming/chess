pipeline {
  agent any
  stages {
    stage('error') {
      steps {
        sh '''chmod +x .ci/compile.sh
.ci/compile.sh'''
      }
    }

  }
}