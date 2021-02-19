#
# Be sure to run `pod lib lint AIFunSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AIFunSDK'
  s.version          = '0.1.0'
  s.summary          = 'A short description of AIFunSDK.'
  
  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  
  s.description      = <<-DESC
  TODO: Add long description of the pod here.
  DESC
  
  s.homepage         = 'https://github.com/LifeForLove/aifun_ios_sdk'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'LifeForLove' => '695946569@qq.com' }
  s.source           = { :git => 'https://github.com/LifeForLove/aifun_ios_sdk.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  
  s.ios.deployment_target = '9.0'
  
#  s.source_files = 'AIFunSDK/Classes/**/*'
  
  s.vendored_frameworks = 'AIFunSDK/AIFunSDK.framework'
  s.resource  = "AIFunSDK/AIFunSDKResource.bundle"
  
  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'Masonry', '~> 1.1.0'
  s.dependency 'SDWebImage', '~> 5.10.4'
  s.dependency 'AFNetworking','~> 4.0.1'
  s.dependency 'MJExtension', '~> 3.2.4'
  s.dependency 'MJRefresh', '~> 3.5.0'
  s.dependency 'YYText', '~> 1.0.7'
  s.dependency 'ReactiveCocoa','~> 2.5'
  s.dependency 'QCloudCOSXML/Transfer','~> 5.8.1' #腾讯cos
  s.dependency 'SAMKeychain','~> 1.5.3'
  s.requires_arc = true
  
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-all_load' }
end
