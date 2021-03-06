// Jenkinsfile v2.0.0
pipeline {
    agent {
			label 'windows'
    }
    parameters {
        string( name: 'NOTIFICATION_EMAIL',
                defaultValue: 'aman.hebbale@microchip.com',
                description: "Email to send build failure and fixed notifications.")
    }
	
	environment {
		GITHUB_OWNER = 'microchip-pic-avr-examples'	
		GITHUB_URL ='https://github.com/mchpTestArea/hex-deployment-test'
		BITBUCKET_URL = 'https://bitbucket.microchip.com/scm/~i64056/hex-deployment-test.git '
		SEMVER_REGEX = '^(0|[1-9]\\d*)+\\.(0|[1-9]\\d*)+\\.(0|[1-9]\\d*)+$'
		ARTIFACTORY_SERVER = 'https://artifacts.microchip.com:7999/artifactory'
	}	
	options {
		timestamps()
		timeout(time: 30, unit: 'MINUTES')
	}

	stages {
		stage('setup') {
		    steps {
				script {
					def githubObj = getGiHubInfo()					
					download("tool-github-deploy","1.4.0")	
					execute("python ./tool-github-deploy/tool-github-deploy/tool-github-deploy.py -deploy=true -gpat=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 -dgid=Aman-hebbale -dburl=${env.BITBUCKET_URL} -dgurl=${env.GITHUB_URL} -dtag=${env.TAG_NAME} -dmfd=true -digmc=true")						
					def PATH_TO_HEX_FILE = "./pic16f15276-cnano-uart-io-expander-client-mplab-mcc.X/dist/default/production"
					execute("cd ${PATH_TO_HEX_FILE} && rename pic16f15276-cnano-uart-io-expander-client-mplab-mcc.X.production.hex pic16f15276-cnano-uart-io-expander-client-mplab-mcc-${env.TAG_NAME}.hex")
					execute("python ./tool-github-deploy/tool-github-deploy/tool-github-deploy.py -rlo=true -gpat=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  -rpn=${githubObj.repoName} -rltv=${env.TAG_NAME} -rltt=${env.TAG_NAME} -rlua=./pic16f15276-cnano-uart-io-expander-client-mplab-mcc.X/dist/default/production/pic16f15276-cnano-uart-io-expander-client-mplab-mcc-${env.TAG_NAME}.hex")
				}
            }
		}
	}
}
def execute(String cmd) {
	if(isUnix()) {
		sh cmd
	} else {
		bat cmd
	}
}
def sendPipelineFailureEmail() {			  
    mail to: "${env.EMAILLIST},${params.NOTIFICATION_EMAIL}",
    subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
    body: "Pipeline failure. ${env.BUILD_URL}"
}
def getGiHubInfo() {
	def githubObj = [
		'ownerName':'',
		'repoName':''
		]
	String[] splitURLString = "${env.GITHUB_URL}".split("/")
	githubObj.repoName = splitURLString[splitURLString.size()-1]
	githubObj.repoName = githubObj.repoName.replace(".git","")
	githubObj.ownerName = splitURLString[splitURLString.size()-2]
	return githubObj
}
def download(String toolName,String toolVersion) {
	def repo = "ivy/citd"
	def url = "${env.ARTIFACTORY_SERVER}/${repo}/${toolName}/${toolVersion}/${toolName}-${toolVersion}.zip"
	def response =bat(script:"curl ${url} -o ${toolName}.zip",returnStdout: true).trim()
	unzip dir:"${toolName}", quiet: true, zipFile: "${toolName}.zip"	
	execute("rm -rf ${toolName}.zip")
}