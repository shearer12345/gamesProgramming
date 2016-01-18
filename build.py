#! /usr/bin/env python3

import subprocess
import os
import sys
import errno
import time

from threading import Thread

fileSuffix = '.asciidoc'
clearTuple = ('.html')


def silentremove(filename):
    try:
        os.remove(filename)
    except OSError as e:
        if e.errno != errno.ENOENT: # errno.ENOENT = no such file or directory
            raise # re-raise exception if a different error occured
            
def clearDirectory(dir):
    for file in os.listdir(dir):
        if file.endswith(clearTuple):
            os.remove(os.path.join(dir, file))

def buildDirectory(dir, reveal=True, pdfReveal=False, purePdf=False):

    #process files
    for file in reversed(os.listdir(dir)):
        if file.endswith(fileSuffix):
            print('Working on', file)
            fileNameWithoutSuffix = file[:-len(fileSuffix)]
            file = os.path.join(dir, file)
            revealFileName = os.path.join(dir, fileNameWithoutSuffix + '.html')
            html5FileName = os.path.join(dir, fileNameWithoutSuffix + '_html5.html' )
            #docxFileName = os.path.join(dir, fileNameWithoutSuffix + '.docx')
            #pdfFileName = os.path.join(dir, fileNameWithoutSuffix + '.pdf')
            #purePdfFileName = os.path.join(dir, fileNameWithoutSuffix + '_pure.pdf')
            #webtexFileName = os.path.join(dir, fileNameWithoutSuffix + '_webtex.html')
            
            if reveal:
                #os.system('asciidoctor -T asciidoctor-reveal.js/templates/slim/ ' + file)
                proc = subprocess.Popen(['asciidoctor -T asciidoctor-reveal.js/templates/slim/ ' + file], stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
                (out, err) = proc.communicate()

                if len(out) > 0:
                    print "program output:", out
                if len(err) > 0:
#                    print "program errors:", err
                    pass
                
#            if purePdf:
#                os.system(pandocBin + ' ' + '-s ' + file + ' -o ' + purePdfFileName + ' -t latex')
#            
#            #pdf of reveal
#            if pdfReveal:
#                phantomString = 'phantomjs ./reveal.js/plugin/print-pdf/print-pdf.js ' + 'http://localhost:8000/' + fileNameWithoutSuffix + '.html' + '?print-pdf#/ ' + pdfFileName
#                os.system(phantomString)
                
clearDirectory('.')
buildDirectory('.')
