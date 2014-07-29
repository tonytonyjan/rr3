# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'rr3/version'

Gem::Specification.new do |spec|
  spec.name          = "rr3"
  spec.version       = Rr3::VERSION
  spec.authors       = ["Tony Jian"]
  spec.email         = ["tonytonyjan@gmail.com"]
  spec.summary       = 'Ruby wrapper of r3 library.'
  spec.description   = 'Ruby wrapper of r3 library.'
  spec.homepage      = "https://github.com/tonytonyjan/rr3"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.extensions    = %w[ext/rr3/extconf.rb]
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.6"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec"
end
