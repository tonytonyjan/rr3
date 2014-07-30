$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  before(:all)do
    @tree = Rr3::Tree.new(10)
    @tree.insert_path "/bar"
    @tree.insert_path "/zoo", 9527
    @tree.insert_path "/foo/bar", 9527
    @tree.insert_path "/post/{id}", 9527
    @tree.insert_path "/user/{id:\\d+}", 9527
    @tree.compile!
  end

  it 'matches' do
    expect(@tree.match("/bar")).to be nil
    expect(@tree.match("/zoo")).to be 9527
    expect(@tree.match("/foo/bar")).to be 9527
    expect(@tree.match("/post/1234")).to be 9527
    expect(@tree.match("/user/1234")).to be 9527
    expect(@tree.match("/user/xxx")).to be false
    expect(@tree.match("/asd")).to be false
  end

  it 'dumps' do
    expect{ @tree.dump(0) }.not_to raise_error
  end

  it 'should returns root node' do
    expect(@tree.root).to be_a Rr3::Node
  end
end
