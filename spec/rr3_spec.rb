$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  before(:each)do
    @tree = Rr3::Tree.new(10)
  end

  it 'works' do
    @tree.insert_path "/foo/bar"
    @tree.compile!
    expect(@tree.match("/foo/bar")).to be nil
    expect(@tree.match("/foo/barr")).to be nil
    @tree.dump(0)
  end

  it 'should pass any data' do
    @tree.insert_path "/foo/bar", 9527
    expect(@tree.match("/foo/bar")).to be 9527
  end

  it 'should returns root node' do
    expect(@tree.root).to be_a Rr3::Node
  end
end
