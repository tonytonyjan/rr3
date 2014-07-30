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
    expect(@tree.match("/bar")).to be_nil
    expect(@tree.match("/asdf")).to be_nil
  end

  it 'dumps' do
    @tree.dump(0)
  end

  it 'should pass any data' do
    expect(@tree.match("/foo/bar")).to eql 9527
    expect(@tree.match("/post/123")).to eql 9527
  end

  it 'should returns root node' do
    expect(@tree.root).to be_a Rr3::Node
  end
end
