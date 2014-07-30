$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  before(:each)do
    @tree = Rr3::Tree.new(10)
  end

  it 'matches' do
    @tree.insert_path "/foo/bar"
    @tree.compile!
    expect(@tree.match("/foo/bar")).to be_nil
    expect(@tree.match("/foo/barr")).to be_nil
  end

  it 'dumps' do
    @tree.insert_path "/foo/bar"
    @tree.compile!
    @tree.dump(0)
  end

  it 'should pass any data' do
    @tree.insert_path "/foo/bar", 9527
    @tree.insert_path "/hello", "Hello"
    @tree.compile!
    expect(@tree.match("/foo/bar")).to eql 9527
    expect(@tree.match("/hello")).to eql "Hello"
  end

  it 'should returns root node' do
    expect(@tree.root).to be_a Rr3::Node
  end
end
