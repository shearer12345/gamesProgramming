require 'asciidoctor'
require 'asciidoctor-revealjs'

#        :backend => 'dzslides',
#        :template_dir => 'asciidoctor-backends/slim/'

desc "Generate html pages using reveal.js"
task :generateReveal, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    output_dir = args[:output_dir]
    puts args
    #TODO(shearer) use asciidoctor-revealjs directly, not through shell
    sh 'bundle exec asciidoctor-revealjs -a revealjsdir=https://cdnjs.cloudflare.com/ajax/libs/reveal.js/3.3.0 ' + filename
end

desc "Generate html pages using just asciidoctor"
task :generateHTML, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    output_dir = args[:output_dir]
    #TODO(shearer) use asciidoctor-revealjs directly, not through shell
    Asciidoctor.convert_file filename,
        :to_dir => output_dir
end
task :default do
     task(:generateReveal).invoke('index.adoc')
     task(:generateReveal).invoke('lecture01_introduction.adoc')
     task(:generateReveal).invoke('lecture02.adoc')
     task(:generateHTML).invoke('workshop01_settingUpABuildSystem.adoc')
end
